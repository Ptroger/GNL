/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:30:08 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/27 09:34:07 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *list;
	
	list = *alst;
	while (list != NULL)
	{
		temp = list->next;
		del(list->content, list->content_size);
		list = temp;
	}
	*alst = NULL;
}
