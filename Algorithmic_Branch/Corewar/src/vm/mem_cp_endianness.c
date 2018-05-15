/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cp_endianness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:05:27 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 18:05:28 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static uint64_t					g_write_pid[9] = {
	[1] = 0x0101010101010101,
	[2] = 0x0202020202020202,
	[3] = 0x0303030303030303,
	[4] = 0x0404040404040404,
	[5] = 0x0505050505050505,
	[6] = 0x0606060606060606,
	[7] = 0x0707070707070707,
	[8] = 0x0808080808080808,
};

static uint16_t					g_op_modulo[OP_END] = {
	[OP_ADD] = IDX_MOD,
	[OP_SUB] = IDX_MOD,
	[OP_ST] = IDX_MOD,
	[OP_STI] = IDX_MOD,
	[OP_LD] = IDX_MOD,
	[OP_LLD] = IDX_MAX,
	[OP_LDI] = IDX_MOD,
	[OP_LLDI] = IDX_MAX,
	[OP_AND] = IDX_MOD,
	[OP_OR] = IDX_MOD,
	[OP_XOR] = IDX_MOD,
	[OP_LIVE] = IDX_MOD,
	[OP_FORK] = IDX_MOD,
	[OP_LFORK] = IDX_MAX,
	[OP_ZJMP] = IDX_MOD,
	[OP_AFF] = IDX_MOD,
};

int16_t							calc_absolute_addr(
	const int16_t offset,
	const t_process *const restrict cur_process)
{
	return (((cur_process->ip + offset % g_op_modulo[cur_process->opcode]) %
		MEM_SIZE + MEM_SIZE) % MEM_SIZE);
}

size_t							mem_cp_endianness(
	void *const dst,
	void *const src,
	const size_t size,
	const uint8_t color_id)
{
	size_t						i;

	i = (size_t)-1;
	if ((uint8_t *)src >= g_shared_memory &&
		(uint8_t *)src < g_shared_memory + MEM_SIZE)
		while (++i < size)
			((uint8_t *)dst)[i] = g_shared_memory[((size - 1 - i) +
				((uint8_t *)src - g_shared_memory)) % MEM_SIZE];
	else if ((uint8_t *)dst >= g_shared_memory &&
		(uint8_t *)dst < g_shared_memory + MEM_SIZE)
	{
		mem_cp_endianness(g_pid_memory + ((uint8_t *)dst - g_shared_memory),
			g_write_pid + color_id, REG_SIZE, 0);
		while (++i < size)
			g_shared_memory[((size - i - 1) + (uint8_t *)dst -
			g_shared_memory) % MEM_SIZE] = ((uint8_t *)src)[i];
		if (g_flags[FLAG_GRAPHICS])
			update_corewar(g_shared_memory, (uint8_t *)dst, size, 1);
	}
	else
		while (++i < size)
			((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
	return (size);
}
