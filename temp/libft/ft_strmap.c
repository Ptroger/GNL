/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:46:22 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/26 18:46:25 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(new) * ft_strlen(s));
	if (new == '\0')
		return (NULL);
	while (s[i])
	{
		new[i] = (f)(s[i]);
		i++;
	}
	return (new);
}
