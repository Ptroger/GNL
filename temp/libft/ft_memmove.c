/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:43:40 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/27 11:31:27 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while ((*(char*)src) != 0)
	{
		if (dest == src)
		{
			i = n;
			while ((int)(i) >= 0)
			{
				((char*)dest)[i] = ((char*)src)[i];
				i--;
			}
			return (dest);
		}
		src++;
	}
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}
