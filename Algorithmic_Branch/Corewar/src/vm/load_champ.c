/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:05:03 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 18:05:04 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t							reverse32(
	const uint32_t a)
{
	return ((a >> 24) + (a << 24) +
		((a >> 8) & 0xFF00) + ((a << 8) & 0xFF0000));
}

static inline void					init_process(
	const t_champ *const restrict champ)
{
	t_process						*process;

	if ((process = allocate_process()))
	{
		process->creator = (t_champ *)champ;
		process->registers.r[1] = champ->color_id;
	}
}

int									load_champ(
	const char *const restrict name,
	const uint8_t pid)
{
	int								fd;

	if (g_champ_index == MAX_PLAYERS + 1)
		exit(write(1, ERROR_MAX_CHAMPS, sizeof(ERROR_MAX_CHAMPS) - 1));
	if (0 >= (fd = open(name, O_RDONLY)) ||
		(read(fd, &g_champs[g_champ_index].header, sizeof(t_header)) <= 0) ||
		(COREWAR_EXEC_MAGIC !=
			reverse32(g_champs[g_champ_index].header.magic)) ||
		(reverse32(g_champs[g_champ_index].header.prog_size) >
			CHAMP_MAX_SIZE) ||
		((read(fd, g_champs[g_champ_index].buffer_code,
			reverse32(g_champs[g_champ_index].header.prog_size)) <= 0)) ||
		(close(fd) < 0))
		exit(write(1, ERROR_INVALID_CHAMPION,
			sizeof(ERROR_INVALID_CHAMPION) - 1));
	g_champs[g_champ_index].color_id = g_champ_index;
	g_champs[g_champ_index].pid = pid;
	init_process(g_champs + g_champ_index);
	return (g_champ_index++);
}
