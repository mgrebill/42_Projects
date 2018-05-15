/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:23:37 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 16:23:38 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int64_t					g_free_processes_stack[MAX_PROCESSES_NUMBER];
static uint64_t					g_free_processes_stack_index;

void							init_free_processes_stack(void)
{
	int64_t						i;

	i = -1;
	while (++i < MAX_PROCESSES_NUMBER)
		g_free_processes_stack[i] = MAX_PROCESSES_NUMBER - i;
	g_free_processes_stack_index = i;
}

static t_process				g_processes[MAX_PROCESSES_NUMBER];

t_process						*allocate_process(void)
{
	t_process					*process;
	uint64_t					process_id;

	if (g_free_processes_stack_index)
	{
		process_id = g_free_processes_stack[--g_free_processes_stack_index];
		process = g_processes + process_id;
		process->id = process_id;
		process->alive = 1;
		process->cycle_left = 0;
		process->previous = g_vm.last_process ? g_vm.last_process : process;
		process->next = g_vm.last_process ? g_vm.last_process->next : process;
		process->ip_last_live = (uint16_t) - 1;
		if (g_vm.last_process)
		{
			g_vm.last_process->next->previous = process;
			g_vm.last_process->next = process;
		}
		g_vm.last_process = process;
		++g_vm.process_number;
	}
	else
		process = 0;
	return (process);
}

void							fork_process(
	const t_process *const restrict process_to_fork,
	const t_reg_type next_ip)
{
	t_process					*process;

	if ((process = allocate_process()))
	{
		process->creator = process_to_fork->creator;
		process->ip = process_to_fork->ip;
		process->zero_flag = process_to_fork->zero_flag;
		process->registers = process_to_fork->registers;
		process->next_ip =
			calc_absolute_addr((int16_t)next_ip, process_to_fork);
	}
}

void							kill_obsolete_process(
	t_process *cur_process)
{
	g_free_processes_stack[g_free_processes_stack_index++] = cur_process->id;
	cur_process->previous->next = cur_process->next;
	cur_process->next->previous = cur_process->previous;
	if (cur_process == g_vm.last_process)
		g_vm.last_process = (cur_process->previous == cur_process ?
			0 : cur_process->previous);
	cur_process->alive = 0;
	cur_process->made_live = 0;
	if (g_flags[FLAG_GRAPHICS])
		update_corewar(g_shared_memory,
			cur_process->ip + g_shared_memory, 1, 1);
	g_vm.process_number--;
}
