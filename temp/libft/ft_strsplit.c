/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:47:56 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/26 18:55:19 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		static malloc_size(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			n++;
			while(s[i] && s[i] != c)
				i++;
		}
	}
	return (n + 1);
}

size_t		static str_malloc(char const *s, char c, int i)
{
	size_t	n;

	n = 0;
	while (s[i] != c && s[i])
	{
		i++;
		n++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab = (char **) malloc (sizeof(tab) * malloc_size(s, c));
	if (tab == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			tab[j] = ft_strsub(s, i, (str_malloc(s, c, i)));
			j++;
			while(s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
