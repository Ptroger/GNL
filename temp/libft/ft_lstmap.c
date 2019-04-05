/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:58:12 by ptroger           #+#    #+#             */
/*   Updated: 2018/11/27 10:51:43 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list *new;
	t_list *buf;

	buf = f(lst);
	if (!(new = ft_lstnew(buf->content, buf->content_size)))
		return (NULL);
	new = buf;
	while (lst->next != NULL)
	{
		if (!(new->next = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (new);
}
