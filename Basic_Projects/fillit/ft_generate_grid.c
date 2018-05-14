/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:03:09 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 21:03:13 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_generate_grid(size_t size)
{
	size_t	i;
	char	**grid;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * (size + 5))))
		return (NULL);
	while (i < size)
	{
		grid[i] = ft_strnew(size + 2);
		grid[i] = ft_memset(grid[i], '.', size);
		i++;
	}
	while (i < size + 4)
	{
		grid[i] = ft_strnew(size + 2);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
