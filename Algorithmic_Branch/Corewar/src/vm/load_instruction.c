/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:01:00 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 18:01:01 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static size_t							g_op_size[4][2] = {
	[0b01][0] = 1,
	[0b10][0] = DIR_SIZE,
	[0b11][0] = IND_SIZE,
	[0b01][1] = 1,
	[0b10][1] = IND_SIZE,
	[0b11][1] = IND_SIZE,
};

static int								g_destination_by_operator[256] = {
	[OP_LIVE] = 0,
	[OP_LD] = 1,
	[OP_ST] = 1,
	[OP_ADD] = 2,
	[OP_SUB] = 2,
	[OP_AND] = 2,
	[OP_OR] = 2,
	[OP_XOR] = 2,
	[OP_ZJMP] = 0,
	[OP_LDI] = 2,
	[OP_STI] = 2,
	[OP_FORK] = 0,
	[OP_LLD] = 1,
	[OP_LLDI] = 2,
	[OP_LFORK] = 0,
	[OP_AFF] = -1,
};

static uint8_t							g_default_mod_byte[256] = {
	[OP_LIVE] = 0b10000000,
	[OP_FORK] = 0b10000000,
	[OP_LFORK] = 0b10000000,
	[OP_ZJMP] = 0b10000000,
};

static uint8_t							g_opl_by_opcode[OP_END] = {
	[OP_LIVE] = 3,
	[OP_LD] = 4,
	[OP_ST] = 5,
	[OP_ADD] = 1,
	[OP_SUB] = 1,
	[OP_AND] = 0,
	[OP_OR] = 0,
	[OP_XOR] = 0,
	[OP_ZJMP] = 3,
	[OP_LDI] = 2,
	[OP_STI] = 6,
	[OP_FORK] = 3,
	[OP_LLD] = 4,
	[OP_LLDI] = 2,
	[OP_LFORK] = 3,
	[OP_AFF] = 7,
};

static uint8_t							g_mod_byte_by_opl[8][255] = {
	[0][0b01010100] = 1,
	[0][0b01100100] = 1,
	[0][0b01110100] = 1,
	[0][0b10010100] = 1,
	[0][0b10100100] = 1,
	[0][0b10110100] = 1,
	[0][0b11010100] = 1,
	[0][0b11100100] = 1,
	[0][0b11110100] = 1,

	[1][0b01010100] = 1,

	[2][0b01010100] = 1,
	[2][0b01100100] = 1,
	[2][0b10010100] = 1,
	[2][0b10100100] = 1,
	[2][0b11010100] = 1,
	[2][0b11100100] = 1,

	[3][0b10000000] = 1,

	[4][0b10010000] = 1,
	[4][0b11010000] = 1,

	[5][0b01010000] = 1,
	[5][0b01110000] = 1,

	[6][0b01010100] = 1,
	[6][0b01011000] = 1,
	[6][0b01100100] = 1,
	[6][0b01101000] = 1,
	[6][0b01110100] = 1,
	[6][0b01111000] = 1,

	[7][0b01000000] = 1,
};

static inline uint16_t					load_operand_from_memory(
	uint8_t operand_id,
	int16_t offset,
	size_t size,
	t_process *cur_process)
{
	void								*absolute_addr;
	size_t								ret;

	absolute_addr = g_shared_memory + calc_absolute_addr(offset, cur_process);
	cur_process->o[operand_id] = 0;
	ret = mem_cp_endianness(cur_process->o + operand_id,
		absolute_addr, size, 0);
	if (size == 2)
		cur_process->o[operand_id] =
			*(int16_t *)(cur_process->o + operand_id);
	return (ret);
}

static inline void						load_destination_pointer(
	t_process *cur_process)
{
	int									operand_mod;
	int									operand_id;

	operand_id = g_destination_by_operator[cur_process->opcode];
	operand_mod = (3 & (cur_process->mod_byte >> (6 - 2 * operand_id)));
	cur_process->dest =
		((IND_MOD == operand_mod) || OP_STI == cur_process->opcode) ?
		(t_reg_type *)(g_shared_memory + calc_absolute_addr(
				cur_process->o[operand_id], cur_process)) :
			cur_process->registers.r + cur_process->o[operand_id] % REG_NUMBER;
}

t_op						g_operator_by_opcode[256] = {
	[OP_LIVE] = {OP_LIVE, "live", 10, 1, 0, 0},
	[OP_LD] = {OP_LD, "ld", 5, 2, 1, 0},
	[OP_ST] = {OP_ST, "st", 5, 2, 1, 0},
	[OP_ADD] = {OP_ADD, "add", 10, 3, 1, 0},
	[OP_SUB] = {OP_SUB, "sub", 10, 3, 1, 0},
	[OP_AND] = {OP_AND, "and", 6, 3, 1, 0},
	[OP_OR] = {OP_OR, "or", 6, 3, 1, 0},
	[OP_XOR] = {OP_XOR, "xor", 6, 3, 1, 0},
	[OP_ZJMP] = {OP_ZJMP, "zjmp", 25, 1, 0, 1},
	[OP_LDI] = {OP_LDI, "ldi", 25, 3, 1, 1},
	[OP_STI] = {OP_STI, "sti", 25, 3, 1, 1},
	[OP_FORK] = {OP_FORK, "fork", 800, 1, 0, 1},
	[OP_LLD] = {OP_LLD, "lld", 10, 2, 1, 0},
	[OP_LLDI] = {OP_LLDI, "lldi", 50, 3, 1, 1},
	[OP_LFORK] = {OP_LFORK, "lfork", 1000, 1, 0, 1},
	[OP_AFF] = {OP_AFF, "aff", 2, 1, 1, 0},
};

static inline size_t					get_operand_size(
	t_process *cur_process,
	int operand_id)
{
	return (g_op_size[3 & (cur_process->mod_byte >> (6 - 2 * operand_id))]
		[g_operator_by_opcode[cur_process->opcode].addr]);
}

static inline void						prepare_operands(
	t_process *cur_process)
{
	int									i;

	i = -1;
	while (++i < 3)
	{
		cur_process->next_ip += load_operand_from_memory(i,
			cur_process->next_ip - cur_process->ip,
			get_operand_size(cur_process, i), cur_process);
		if (i != g_destination_by_operator[cur_process->opcode] ||
			OP_STI == cur_process->opcode)
		{
			if (REG_MOD == (3 & (cur_process->mod_byte >> (6 - 2 * i))))
				cur_process->o[i] =
					cur_process->registers.r[cur_process->o[i] % REG_NUMBER];
			else if (IND_MOD == (3 & (cur_process->mod_byte >> (6 - 2 * i))))
				load_operand_from_memory(
					i, cur_process->o[i], REG_SIZE, cur_process);
		}
	}
	if (OP_LDI == cur_process->opcode || OP_LLDI == cur_process->opcode)
		load_operand_from_memory(0, cur_process->o[0] + cur_process->o[1],
			REG_SIZE, cur_process);
	if (OP_STI == cur_process->opcode)
		cur_process->o[2] = calc_absolute_addr((cur_process->o[1] +
			cur_process->o[2]), cur_process) - cur_process->ip;
}

void									load_instruction(
	t_process *cur_process)
{
	if (g_flags[FLAG_GRAPHICS])
	{
		print_ip(g_shared_memory, g_shared_memory + cur_process->ip, 0);
		print_ip(g_shared_memory,
			g_shared_memory + cur_process->next_ip % MEM_SIZE, 1);
	}
	cur_process->ip = cur_process->next_ip % MEM_SIZE;
	cur_process->opcode = g_shared_memory[cur_process->next_ip++ % MEM_SIZE];
	cur_process->mod_byte = g_default_mod_byte[cur_process->opcode] ?
		g_default_mod_byte[cur_process->opcode] :
		g_shared_memory[cur_process->next_ip % MEM_SIZE];
	if (cur_process->opcode && cur_process->opcode < OP_END &&
		g_mod_byte_by_opl
			[g_opl_by_opcode[cur_process->opcode]][cur_process->mod_byte])
	{
		cur_process->next_ip +=
			g_operator_by_opcode[cur_process->opcode].uses_mod_byte;
		prepare_operands(cur_process);
		if (0 < g_destination_by_operator[cur_process->opcode])
			load_destination_pointer(cur_process);
		cur_process->cycle_left =
			g_operator_by_opcode[cur_process->opcode].nbr_cycles;
	}
}
