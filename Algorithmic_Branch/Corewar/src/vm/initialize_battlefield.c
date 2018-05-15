/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_battlefield.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:02:18 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 18:02:19 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static inline void				swap_processes(
	t_process *const red,
	t_process *const green)
{
	if (green->next != red)
	{
		red->next = green->next;
		green->previous = red->previous;
		red->previous->next = green;
		green->next->previous = red;
		green->next = red;
		red->previous = green;
	}
	if (red == g_vm.last_process)
		g_vm.last_process = green;
	else if (green == g_vm.last_process)
		g_vm.last_process = red;
}

static inline void				sort_processes(void)
{
	t_process					*cur_process;
	int							not_first;

	not_first = 0;
	cur_process = g_vm.last_process->next;
	while (cur_process->previous != g_vm.last_process || !not_first++)
	{
		if (cur_process->creator->pid >
			cur_process->next->creator->pid && cur_process != g_vm.last_process)
		{
			swap_processes(cur_process, cur_process->next);
			not_first = 0;
			cur_process = g_vm.last_process;
		}
		cur_process = cur_process->next;
	}
}

static inline void				place_champions(void)
{
	t_process					*cur_process;
	size_t						e;
	size_t						i;
	int							not_first;

	not_first = 0;
	cur_process = g_vm.last_process->next;
	e = 0;
	while (cur_process->previous != g_vm.last_process || !not_first++)
	{
		cur_process->next_ip =
			((MEM_SIZE / (g_champ_index - 1)) * e++) % MEM_SIZE;
		cur_process->ip = cur_process->next_ip;
		i = (size_t)-1;
		while (++i < reverse32(cur_process->creator->header.prog_size))
		{
			g_shared_memory[cur_process->ip + i] =
				cur_process->creator->buffer_code[i];
			g_pid_memory[cur_process->ip + i] = cur_process->creator->color_id;
		}
		if (g_flags[FLAG_GRAPHICS])
			print_ip(g_shared_memory, g_shared_memory + cur_process->ip, 1);
		cur_process = cur_process->next;
	}
}

void							initialize_battlefied(void)
{
	place_champions();
	if (g_flags[FLAG_GRAPHICS])
		init_print();
	sort_processes();
}
