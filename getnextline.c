/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:11:23 by ptroger           #+#    #+#             */
/*   Updated: 2018/12/10 18:53:12 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "getnextline.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char		*end;
	int			i;
	char		*buff;
	static char	*stock;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(buff = malloc(sizeof(char*) * BUFF_SIZE)))
		return (-1);
	while ((!(ft_strchr(buff, '\n')) && (i = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[i] = '\0';

		
		rintf("%s\n", buff);
		if (!(stock = ft_strdup(buff)))
			return (-1);
		printf("\n");
	//	free(buff);
	}
		*line = ft_strjoin(stock, buff);
	return (1);
}

int	main(int ac, char **av)
{
	int fd;
	char	*line = NULL;
	
	fd = open(av[1], O_RDONLY);


	if (get_next_line(fd, &line))
	{
//		printf("%d %s\n", get_next_line(fd, &line), line);
		line++;
	}
	return (0);
}
