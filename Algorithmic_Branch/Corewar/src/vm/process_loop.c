/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:31:06 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 16:31:07 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int64_t						g_abstract_cycle_to_die = CYCLE_TO_DIE;
int64_t						g_concrete_cycle_to_die = CYCLE_TO_DIE;

static uint64_t						g_is_writing_op[256] = {
	[OP_ADD] = 1,
	[OP_SUB] = 1,
	[OP_ST] = 1,
	[OP_STI] = 1,
	[OP_LD] = 1,
	[OP_LLD] = 1,
	[OP_LDI] = 1,
	[OP_LLDI] = 1,
	[OP_AND] = 1,
	[OP_OR] = 1,
	[OP_XOR] = 1,
};

static uint64_t						g_is_fork_instruction[OP_END] = {
	[OP_FORK] = 1,
	[OP_LFORK] = 1,
};

static t_mask						g_operand_masks[OP_END] =
{
	[OP_ADD] = {.v = 1, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_SUB] = {.v = -1, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_ST] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_STI] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_LD] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_LLD] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_LDI] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_LLDI] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = 0},
	[OP_AND] = {.v = 0, .and = 0, .or = 0, .xor = 0},
	[OP_OR] = {.v = 0, .and = BITWISE_MASK, .or = BITWISE_MASK, .xor = 0},
	[OP_XOR] = {.v = 0, .and = BITWISE_MASK, .or = 0, .xor = BITWISE_MASK},
};

static int							g_operator_by_opcode_sets_zero[256] = {
	[OP_LIVE] = 0,
	[OP_LD] = 1,
	[OP_ST] = 0,
	[OP_ADD] = 1,
	[OP_SUB] = 1,
	[OP_AND] = 1,
	[OP_OR] = 1,
	[OP_XOR] = 1,
	[OP_ZJMP] = 0,
	[OP_LDI] = 0,
	[OP_STI] = 0,
	[OP_FORK] = 0,
	[OP_LLD] = 1,
	[OP_LLDI] = 1,
	[OP_LFORK] = 0,
	[OP_AFF] = 0,
};

static inline int					updt_cycle_to_die(void)
{
	if (g_vm.nbr_live >= NBR_LIVE || g_vm.nbr_checks >= MAX_CHECKS)
	{
		g_abstract_cycle_to_die -= CYCLE_DELTA;
		if (g_abstract_cycle_to_die <= 0)
			return (1);
		g_vm.nbr_checks = 0;
		g_vm.nbr_live = 0;
	}
	else
		g_vm.nbr_checks++;
	if (g_flags[FLAG_GRAPHICS])
		reset_process_live();
	g_concrete_cycle_to_die = g_abstract_cycle_to_die;
	return (0);
}

static inline void					make_live(t_process *process)
{
	int								size;

	if (process->o[0] > 0 && process->o[0] < g_champ_index)
	{
		g_vm.last_man_standing = g_champs + process->o[0];
		if (g_flags[FLAG_GRAPHICS])
			process->ip_last_live =
				print_live(process->o[0], process->ip, process->ip_last_live);
		iprint(1, "un processus rapporte que le joueur ", 36);
		iprint_nbr(g_vm.last_man_standing->pid);
		iprint(1, " (", 2);
		size = 0;
		while (g_vm.last_man_standing->header.prog_name[size])
			++size;
		iprint(1, g_vm.last_man_standing->header.prog_name, size);
		iprint(1, ")", 1);
		iprint(1, " est en vie\n", 12);
		process->made_live = 1;
	}
	g_vm.nbr_live++;
}

static inline void					execute_instruction(
	t_process *process)
{
	t_mask							mask;
	t_reg_type						tmp;

	mask = g_operand_masks[process->opcode];
	tmp = (((process->o[0] | (process->o[1] & mask.or)) &
		(process->o[1] | mask.and)) ^
		(process->o[1] & mask.xor)) + process->o[1] * mask.v;
	if (g_operator_by_opcode_sets_zero[process->opcode])
		process->zero_flag = !tmp;
	if (g_is_writing_op[process->opcode])
		mem_cp_endianness(process->dest, &tmp, REG_SIZE,
			process->creator->color_id);
	else if (g_is_fork_instruction[process->opcode])
		fork_process(process, process->o[0]);
	else if (OP_ZJMP == process->opcode)
		process->next_ip = !process->zero_flag ? process->next_ip :
			calc_absolute_addr((int16_t)process->o[0], process);
	else if (OP_LIVE == process->opcode)
		make_live(process);
	else if (OP_AFF == process->opcode && g_flags[FLAG_GRAPHICS])
		print_aff(process->creator->color_id, *(char *)(process->o + 0));
	else if (OP_AFF == process->opcode)
		iprint(1, (char *)(process->o + 0), 1);
}

static inline void					treat_process(
	t_process *const restrict cur_process,
	const int64_t cycle)
{
	if (cur_process->alive)
	{
		if (cur_process->cycle_left)
		{
			if (1 == cur_process->cycle_left)
				execute_instruction(cur_process);
			--cur_process->cycle_left;
		}
		else
			load_instruction(cur_process);
	}
	if (1 == g_concrete_cycle_to_die && cycle)
	{
		if (!cur_process->made_live)
			kill_obsolete_process(cur_process);
		else
		{
			cur_process->made_live = 0;
			if (g_flags[FLAG_GRAPHICS])
				update_corewar(g_shared_memory,
					cur_process->ip_last_live + 1 + g_shared_memory, 4, 1);
		}
	}
}

void								process_loop(void)
{
	t_process						*cur_process;
	t_process						*first_process;
	int64_t							cycle;

	cur_process = g_vm.last_process;
	cycle = 0;
	while ((!g_flags[FLAG_DUP] || g_flag_nbrs[FLAG_DUP] != cycle) &&
		g_vm.last_process)
	{
		first_process = g_vm.last_process->next;
		treat_process(cur_process, cycle);
		if (g_flags[FLAG_GRAPHICS])
			check_situation(cycle);
		if (!g_vm.last_process)
			break ;
		if (cur_process == first_process)
		{
			--g_concrete_cycle_to_die;
			if (!g_concrete_cycle_to_die && cycle && updt_cycle_to_die())
				break ;
			++cycle;
		}
		cur_process = cur_process->previous;
	}
}
