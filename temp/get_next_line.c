#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "fcntl.h"

static void		join_stk(char **str, char *stk, int ret)
{
	char *ptr;
	stk[ret] = '\0';
	ptr = *str;
	*str = ft_strjoin(*str, stk);
	ft_strdel(&ptr);
}

int				get_next_line(int const fd, char **line)
{
	int			len;
	static char	*str[256];
	char		*ptr;
	char		*stk;
	int			ret;

	
	if (fd < 0 || BUFF_SIZE <= 0 || !line || !(stk = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	str[fd] = !str[fd] ? ft_strnew(1) : str[fd];
	while (!(ft_strchr(str[fd], '\n')) && (ret = read(fd, stk, BUFF_SIZE)) > 0)
		join_stk(&str[fd], stk, ret);
if (ret == -1)
		return (-1);
	if (ret == 0 && !(ft_strchr(str[fd], '\n')))
	{
		*line = str[fd];
		str[fd] = NULL;
		return (((*line)[0] == '\0') ? 0 : 1);
	}
	len = ft_strchr(str[fd], '\n') - str[fd];
	*line = ft_strsub(str[fd], 0, len);
	ptr = str[fd];
	str[fd] = ft_strdup(ft_strchr(str[fd], '\n') + 1);
	ft_strdel(&ptr);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}
	if (argc == 2)
		close(fd);
}
