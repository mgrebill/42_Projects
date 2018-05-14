/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:39:14 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/16 10:11:05 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;
	t_list	*previous;

	new = f(lst);
	if (!(begin = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	previous = begin;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (!(previous->next = ft_lstnew(new->content, new->content_size)))
			return (NULL);
		previous = previous->next;
		lst = lst->next;
	}
	return (begin);
}
