/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:02:34 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/27 15:08:59 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_trimlen(char *str, size_t len)
{
	while (*str)
	{
		if (!(ft_isspace(*str)))
				ft_trimlen(str + 1, len++);
		return(ft_trimlen(str + 1, len));
	}
	return (len + 1);
}
