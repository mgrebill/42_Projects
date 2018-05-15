/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:23:26 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 16:23:27 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern char						g_color_by_pid[8][5];
extern char						g_background_by_pid[8][5];
uint8_t							g_shared_memory[MEM_SIZE];
uint8_t							g_champ_index = 1;
t_champ							g_champs[MAX_PLAYERS + 1];
t_vm							g_vm;

void							print_winner(void)
{
	int							size;

	if (g_vm.last_man_standing)
	{
		iprint(1, "Le joueur ", 10);
		iprint_nbr(g_vm.last_man_standing->pid);
		iprint(1, "(", 1);
		size = 0;
		while (g_vm.last_man_standing->header.prog_name[size])
			++size;
		iprint(1, g_vm.last_man_standing->header.prog_name, size);
		iprint(1, ") a gagne.\n", 11);
	}
	else
		iprint(1, MSG_NO_WINNER, sizeof(MSG_NO_WINNER) - 1);
}

int								main(
	const int argc,
	const char **argv)
{
	init_free_processes_stack();
	load_argv(argc, argv);
	initialize_battlefied();
	process_loop();
	if (g_flags[FLAG_GRAPHICS])
		print_winner_graphics();
	else if (g_flags[FLAG_DUP])
		print_shared_memory(g_shared_memory, 0, 0, 1);
	else
		print_winner();
	return (0);
}
