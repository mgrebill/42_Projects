/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champ_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 08:06:58 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/03 08:06:59 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>
#include <termios.h>

static int							g_player_lives[9];
static int							g_player_aff[9];

void								check_situation(int64_t cycle)
{
	set_cursor(288 + sizeof(GRAPH_CYCLE), 22);
	print_nbr_base(cycle, 10);
	write(1, "          ", 10);
	set_cursor(288 + sizeof(GRAPH_CYCLE_DIE), 25);
	print_nbr_base(g_concrete_cycle_to_die, 10);
	write(1, " ", 1);
	set_cursor(288 + sizeof(GRAPH_CYCLE_DIE) + 5, 25);
	write(1, " / ", 3);
	print_nbr_base(g_abstract_cycle_to_die, 10);
	write(1, "          ", 10);
	set_cursor(288 + sizeof(GRAPH_DELTA), 28);
	print_nbr_base(CYCLE_DELTA, 10);
	write(1, "          ", 10);
	set_cursor(288 + sizeof(GRAPH_CHECKS), 31);
	print_nbr_base(g_vm.nbr_checks, 10);
	write(1, " ", 1);
	set_cursor(288 + sizeof(GRAPH_CHECKS) + 3, 31);
	write(1, " / ", 3);
	print_nbr_base(MAX_CHECKS, 10);
	write(1, "          ", 10);
	set_cursor(288 + sizeof(GRAPH_NB_PROC), 34);
	print_nbr_base(g_vm.process_number, 10);
	write(1, "          ", 10);
}

void								reset_process_live(void)
{
	int								i;
	int								e;

	i = 0;
	while (i <= g_champ_index - 1)
	{
		set_cursor(LIVE_BAR_POS_X + 1, LIVE_BAR_POS_Y + 1 +
			i * (LIVE_BAR_HEIGHT + LIVE_BAR_SPACE));
		e = 0;
		while (e++ < CHAT_BOX_WIDTH - 5)
			write(1, " ", 1);
		g_player_lives[i] = 0;
		++i;
	}
}

uint16_t							print_live(
	const t_reg_type color_id,
	const uint16_t ip,
	const uint16_t ip_last_live)
{
	if (ip_last_live < MEM_SIZE)
		update_corewar(g_shared_memory,
			g_shared_memory + ip_last_live + 1, 4, 1);
	write(1, g_background_by_pid[color_id], 5);
	write(1, SET_BOLD, 4);
	update_corewar(g_shared_memory, g_shared_memory + ip + 1, 4, 0);
	g_player_lives[0] %= CHAT_BOX_WIDTH - 5;
	g_player_lives[color_id] %= CHAT_BOX_WIDTH - 5;
	set_cursor(LIVE_BAR_POS_X + 1 + g_player_lives[0]++,
		LIVE_BAR_POS_Y + 1);
	write(1, g_background_by_pid[color_id], 5);
	write(1, " ", 1);
	set_cursor(LIVE_BAR_POS_X + 1 + g_player_lives[color_id]++,
		LIVE_BAR_POS_Y + 1 + color_id *
		(LIVE_BAR_HEIGHT + LIVE_BAR_SPACE));
	write(1, " ", 1);
	write(1, RESET_FORMAT, sizeof(RESET_FORMAT) - 1);
	set_cursor(999, 999);
	return (ip);
}

void								print_aff(
	const t_reg_type color_id,
	const char c)
{
	int								pos;

	pos = g_player_aff[color_id]++ % ((CHAT_BOX_WIDTH - 2) *
		(CHAT_BOX_HEIGHT - 4));
	write(1, g_color_by_pid[color_id], 5);
	set_cursor(CHAR_BOX_POS_X + 1 + pos % (CHAT_BOX_WIDTH - 2),
		CHAR_BOX_POS_Y + 3 + (color_id - 1) *
		(CHAT_BOX_SPACE + CHAT_BOX_HEIGHT) +
		pos / (CHAT_BOX_WIDTH - 2));
	write(1, &c, 1);
	write(1, RESET_FORMAT, sizeof(RESET_FORMAT) - 1);
	set_cursor(999, 999);
}

void								print_winner_graphics(void)
{
	print_shared_memory(g_shared_memory, X_MEM, Y_MEM, 0);
	if (!g_flags[FLAG_DUP])
		print_winner();
	else
	{
		iprint(1, MESSAGE_DUP, sizeof(MESSAGE_DUP) - 1);
		iprint_nbr(g_flag_nbrs[FLAG_DUP]);
		iprint(1, "\n", 1);
	}
	iprint(1, MESSAGE_THANKS, sizeof(MESSAGE_THANKS) - 1);
	iprint(1, MESSAGE_QUIT, sizeof(MESSAGE_QUIT) - 1);
	set_cursor(999, 999);
	getchar();
	write(1, SHOW_CURSOR, sizeof(SHOW_CURSOR) - 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_old_term);
	write(1, CLEAR_DISPLAY, sizeof(CLEAR_DISPLAY) - 1);
	system("clear");
}
