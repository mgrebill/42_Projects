/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_pieces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:04:37 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 21:04:39 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_del_one_piece(t_tris **ptr_list)
{
	int	i;

	i = 0;
	free(*ptr_list);
	*ptr_list = NULL;
}

void	ft_lst_del_pieces(t_tris **begin_list)
{
	t_tris	*tmp;

	while (*begin_list)
	{
		tmp = *begin_list;
		ft_lst_del_one_piece(&tmp);
		(*begin_list) = (*begin_list)->next;
	}
}
