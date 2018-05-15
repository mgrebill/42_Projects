/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 07:34:29 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/03 07:34:31 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <termios.h>
#include "vm.h"

struct termios						g_old_term;

char								g_color_by_pid[8][5] = {
	[0] = "\033[00m",
	[1] = "\033[31m",
	[2] = "\033[32m",
	[3] = "\033[33m",
	[4] = "\033[34m",
	[5] = "\033[35m",
	[6] = "\033[36m",
	[7] = "\033[37m",
};

char								g_background_by_pid[8][5] = {
	[0] = "\033[40m",
	[1] = "\033[41m",
	[2] = "\033[42m",
	[3] = "\033[43m",
	[4] = "\033[44m",
	[5] = "\033[45m",
	[6] = "\033[46m",
	[7] = "\033[47m",
};

uint8_t								g_pid_memory[MEM_SIZE];

void								print_shared_memory(
	const uint8_t *const restrict memory,
	int x,
	int y,
	int dump)
{
	size_t	i;

	i = 0;
	if (!dump)
		set_cursor(x, y);
	while (i < MEM_SIZE)
	{
		if (!dump)
			write(1, g_color_by_pid[g_pid_memory[i % MEM_SIZE]], 5);
		write(1, "0", memory[i] < 16 ? 1 : 0);
		print_nbr_base(memory[i++], 16);
		write(1, " ", !(i % BYTES_PER_ROW) ? 0 : 1);
		if (!dump)
		{
			if (!(i % BYTES_PER_ROW))
				set_cursor_new_line(x);
		}
		else
			write(1, "\n", i % BYTES_PER_ROW ? 0 : 1);
	}
	if (!dump)
	{
		write(1, RESET_FORMAT, sizeof(RESET_FORMAT) - 1);
		set_cursor(999, 999);
	}
}

void								print_ip(
	const uint8_t *const memory,
	uint8_t *slot,
	uint8_t print)
{
	if (print)
	{
		if (!g_pid_memory[slot - memory])
		{
			write(1, g_background_by_pid[7], 5);
			write(1, "\033[30m", 5);
		}
		else
		{
			write(1, g_background_by_pid[g_pid_memory[slot - memory]], 5);
			write(1, "\033[30m", 5);
		}
		update_corewar(memory, slot, 1, 0);
	}
	else
	{
		write(1, g_background_by_pid[0], 5);
		update_corewar(memory, slot, 1, 1);
	}
}

void								update_corewar(
	const uint8_t *const memory,
	uint8_t *slot,
	size_t size,
	uint8_t color)
{
	size_t	i;
	uint8_t	already_reseted;

	i = 0;
	set_cursor(((size_t)((slot - memory) % BYTES_PER_ROW) * 3) + X_MEM,
		((size_t)(slot - memory) / BYTES_PER_ROW) + Y_MEM);
	already_reseted = 0;
	while (i < size)
	{
		write(1, g_color_by_pid[g_pid_memory[(slot - memory + i) %
			MEM_SIZE]], color ? 5 : 0);
		write(1, "0", memory[(slot - memory + i) % MEM_SIZE] < 16 ? 1 : 0);
		print_nbr_base(memory[(slot - memory + i) % MEM_SIZE], 16);
		i++;
		write(1, " ", !((((slot - memory + i) % MEM_SIZE) %
			BYTES_PER_ROW) && i < size) ? 0 : 1);
		if (!(((slot - memory + i) % MEM_SIZE) % BYTES_PER_ROW))
			set_cursor_new_line(X_MEM);
		if (slot - memory + i >= MEM_SIZE && !already_reseted)
			set_cursor(X_MEM, Y_MEM + (already_reseted = 1) - 1);
	}
	write(1, RESET_FORMAT, 4);
	set_cursor(999, 999);
}
