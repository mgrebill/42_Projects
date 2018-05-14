/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:52:44 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/30 14:49:20 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putstr("usage: ./fillit <file>\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	size_t	size;
	char	**grid;
	t_tris	*pieces;

	if (argc != 2)
		ft_usage();
	pieces = check_parse(argv[1]);
	size = ft_sizeofgrid(ft_nbpiecetab(pieces));
	grid = ft_generate_grid(size);
	while (!ft_fill_it(pieces, 0, size, grid))
	{
		ft_free_tab_tab(&grid);
		size++;
		grid = ft_generate_grid(size);
	}
	ft_print_str_table(grid);
	ft_lst_del_pieces(&pieces);
	ft_free_tab_tab(&grid);
	return (0);
}
