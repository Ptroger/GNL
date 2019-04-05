/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:48:54 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/26 18:49:02 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		cpy;

	cpy = 0;
	result = (char *)malloc (sizeof(s) * len + 1);
	if (result == NULL)
		return (NULL);
	while (cpy < len)
	{
		result[cpy] = s[start];
		cpy++;
		start++;
	}
	return (result);
}
