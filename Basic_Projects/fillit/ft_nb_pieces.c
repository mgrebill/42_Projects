/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:45:52 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/30 14:50:09 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_nbpiecetab(t_tris *piece)
{
	t_tris	*tmp;
	size_t	size;

	size = 0;
	tmp = piece;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

size_t	ft_sizeofgrid(size_t stab)
{
	size_t	size;

	size = 0;
	stab *= 4;
	while (size * size < stab)
		size++;
	return (size);
}
