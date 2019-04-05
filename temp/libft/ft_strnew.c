/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:47:26 by ptroger           #+#    #+#             */
/*   Updated: 2019/03/01 14:02:07 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*new;
	int			i;
	i = (int)size;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i > 0)
		new [i--] = '\0';
	return (new);
}
