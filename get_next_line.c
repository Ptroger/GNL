#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

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
	static char	*str[MAX_FD];
	char		*ptr;
	char		*stk;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || !(stk = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	str[fd] = !str[fd] ? ft_strnew(1) : str[fd];
	while (!(ft_strchr(str[fd], '\n')) && (ret = read(fd, stk, BUFF_SIZE)) > 0)
		join_stk(&str[fd], stk, ret);
	free(stk);
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

int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	pid_t	child;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open("me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, &n, 1);					// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	close(fd);
	close(fd2);
	child = fork();
	if (child == 0)
	{
		char	*arg[] = {"/usr/bin/diff", NULL, "me.txt", NULL};

		arg[1] = argv[1];
		execve(arg[0], arg, NULL);
		exit(0);
	}
	else
		wait(NULL); // bad code I know ... but it's not the project
	(void)argc;
	(void)argv;
	return (0);
}
