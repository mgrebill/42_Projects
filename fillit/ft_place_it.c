/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:12:31 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 21:12:43 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_it(t_tris *piece, size_t x, size_t y, char **grid)
{
	grid[x][y] = piece->index;
	grid[x + piece->x_1][y + piece->y_1] = piece->index;
	grid[x + piece->x_2][y + piece->y_2] = piece->index;
	grid[x + piece->x_3][y + piece->y_3] = piece->index;
}

void	ft_remove_it(t_tris *piece, size_t p, size_t size, char **grid)
{
	size_t		x;
	size_t		y;

	x = p / size;
	y = p % size;
	grid[x][y] = '.';
	grid[x + piece->x_1][y + piece->y_1] = '.';
	grid[x + piece->x_2][y + piece->y_2] = '.';
	grid[x + piece->x_3][y + piece->y_3] = '.';
}

int		ft_check_place(t_tris *piece, size_t x, size_t y, char **grid)
{
	if (grid[x][y] == '.' &&
	grid[x + piece->x_1][y + piece->y_1] == '.' &&
	grid[x + piece->x_2][y + piece->y_2] == '.' &&
	grid[x + piece->x_3][y + piece->y_3] == '.')
		return (1);
	return (0);
}

int		ft_fill_it(t_tris *piece, size_t p, size_t size, char **grid)
{
	size_t		x;
	size_t		y;

	x = p / size;
	y = p % size;
	if (!piece)
		return (1);
	if (p == size * size)
		return (0);
	if (ft_check_place(piece, x, y, grid))
	{
		ft_place_it(piece, x, y, grid);
		if (ft_fill_it(piece->next, 0, size, grid))
			return (1);
		else
			ft_remove_it(piece, p, size, grid);
	}
	return (ft_fill_it(piece, p + 1, size, grid));
}
