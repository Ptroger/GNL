/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:46:00 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/28 10:24:21 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_strtrim(char const *s)
{
	size_t	len;
	int		i;
	int		c; 
	char	*new;

	c = 0;
	len = 0;
	i = 0;
	len = ft_trimlen((char*)(s), len);

	if (!(new = (char *) malloc (sizeof(new) * len + 2)))
		return (NULL);
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		new[c] = s[i];
		c++;
		i++;
	}
	//new[c] = '\n';
	//new[c++] = '\0';
	return (new);
}
