/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:31:39 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/30 12:31:42 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_affect_coor(t_tris *new, int x, int y, int square)
{
	if (square == 1)
	{
		new->x_1 = x;
		new->y_1 = y;
	}
	if (square == 2)
	{
		new->x_2 = x;
		new->y_2 = y;
	}
	if (square == 3)
	{
		new->x_3 = x;
		new->y_3 = y;
	}
}

void	ft_find_coor(t_tris **new, char **piece)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		square;

	i = 0;
	x = 0;
	y = 0;
	square = 0;
	while (square != 4)
	{
		if (square)
			y = -j;
		else
			j = 0;
		while (piece[i + x][j + y])
		{
			if (piece[i + x][j + y] == '#')
				ft_affect_coor(*new, x, y, square++);
			(square) ? y++ : j++;
		}
		(square) ? x++ : i++;
	}
}

t_tris	*ft_lst_new_piece(char index, char **piece)
{
	t_tris	*new;

	if (!(new = (t_tris *)malloc(sizeof(t_tris))))
		return (NULL);
	ft_find_coor(&new, piece);
	new->index = index;
	new->next = NULL;
	return (new);
}
