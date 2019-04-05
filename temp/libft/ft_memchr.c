/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:16:06 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/15 14:20:26 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (((char*)s)[i] != c && i <= n)
		i++;
	if (((char*)s)[i] == c)
		return ((char*)s);
	return (NULL);
}
