/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_piece_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:03:27 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 21:03:29 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_add_piece_end(t_tris **begin_list, t_tris *new)
{
	t_tris	*tmp;

	tmp = (*begin_list);
	if (!(*begin_list))
	{
		(*begin_list) = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
