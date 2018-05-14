/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:15:13 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/19 18:28:26 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;

	new = NULL;
	if (lst && (*f))
	{
		tmp = f(lst);
		new = ft_lstnew(tmp->content, tmp->content_size);
		free(tmp);
		new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
