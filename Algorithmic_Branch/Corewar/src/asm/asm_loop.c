/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:54:00 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 16:54:02 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t						g_line_i;
size_t						g_char_i;

static int					g_mod_mask[STATE_END] = {
	[OPL1_OP1REG] = 0b00111100,
	[OPL1_OP1DIR] = 0b00111100,
	[OPL1_OP2REG] = 0b11001100,
	[OPL1_OP2DIR] = 0b11001100,
	[OPL1_OP3REG] = 0b11110000,
	[OPL1_OP3DIR] = 0b11110000,

	[OPL2_OP1REG] = 0b00111100,
	[OPL2_OP1DIR] = 0b00111100,
	[OPL2_OP2REG] = 0b11001100,
	[OPL2_OP2DIR] = 0b11001100,
	[OPL2_OP3REG] = 0b11110000,
	[OPL2_OP3DIR] = 0b11110000,

	[OPL3_OP1REG] = 0b00111100,
	[OPL3_OP1DIR] = 0b00111100,
	[OPL3_OP2REG] = 0b11001100,
	[OPL3_OP2DIR] = 0b11001100,
	[OPL3_OP3REG] = 0b11110000,
	[OPL3_OP3DIR] = 0b11110000,

	[OPL4_OP1REG] = 0b00111100,
	[OPL4_OP1DIR] = 0b00111100,
	[OPL4_OP2REG] = 0b11001100,
	[OPL4_OP2DIR] = 0b11001100,
	[OPL4_OP3REG] = 0b11110000,
	[OPL4_OP3DIR] = 0b11110000,

	[OPL5_OP1REG] = 0b00111100,
	[OPL5_OP1DIR] = 0b00111100,
	[OPL5_OP2REG] = 0b11001100,
	[OPL5_OP2DIR] = 0b11001100,
	[OPL5_OP3REG] = 0b11110000,
	[OPL5_OP3DIR] = 0b11110000,

	[OPL6_OP1REG] = 0b00111100,
	[OPL6_OP1DIR] = 0b00111100,
	[OPL6_OP2REG] = 0b11001100,
	[OPL6_OP2DIR] = 0b11001100,
	[OPL6_OP3REG] = 0b11110000,
	[OPL6_OP3DIR] = 0b11110000,

	[OPL7_OP1REG] = 0b00111100,
	[OPL7_OP1DIR] = 0b00111100,
	[OPL7_OP2REG] = 0b11001100,
	[OPL7_OP2DIR] = 0b11001100,
	[OPL7_OP3REG] = 0b11110000,
	[OPL7_OP3DIR] = 0b11110000,

	[OPL8_OP1REG] = 0b00111100,
	[OPL8_OP1DIR] = 0b00111100,
	[OPL8_OP2REG] = 0b11001100,
	[OPL8_OP2DIR] = 0b11001100,
	[OPL8_OP3REG] = 0b11110000,
	[OPL8_OP3DIR] = 0b11110000,
};

static int					g_mod_set[STATE_END] = {
	[OPL1_OP1REG] = 0b01000000,
	[OPL1_OP1DIR] = 0b10000000,
	[OPL1_OP2REG] = 0b00010000,
	[OPL1_OP2DIR] = 0b00100000,
	[OPL1_OP3REG] = 0b00000100,
	[OPL1_OP3DIR] = 0b00001000,

	[OPL2_OP1REG] = 0b01000000,
	[OPL2_OP1DIR] = 0b10000000,
	[OPL2_OP2REG] = 0b00010000,
	[OPL2_OP2DIR] = 0b00100000,
	[OPL2_OP3REG] = 0b00000100,
	[OPL2_OP3DIR] = 0b00001000,

	[OPL3_OP1REG] = 0b01000000,
	[OPL3_OP1DIR] = 0b10000000,
	[OPL3_OP2REG] = 0b00010000,
	[OPL3_OP2DIR] = 0b00100000,
	[OPL3_OP3REG] = 0b00000100,
	[OPL3_OP3DIR] = 0b00001000,

	[OPL4_OP1REG] = 0b01000000,
	[OPL4_OP1DIR] = 0b10000000,
	[OPL4_OP2REG] = 0b00010000,
	[OPL4_OP2DIR] = 0b00100000,
	[OPL4_OP3REG] = 0b00000100,
	[OPL4_OP3DIR] = 0b00001000,

	[OPL5_OP1REG] = 0b01000000,
	[OPL5_OP1DIR] = 0b10000000,
	[OPL5_OP2REG] = 0b00010000,
	[OPL5_OP2DIR] = 0b00100000,
	[OPL5_OP3REG] = 0b00000100,
	[OPL5_OP3DIR] = 0b00001000,

	[OPL6_OP1REG] = 0b01000000,
	[OPL6_OP1DIR] = 0b10000000,
	[OPL6_OP2REG] = 0b00010000,
	[OPL6_OP2DIR] = 0b00100000,
	[OPL6_OP3REG] = 0b00000100,
	[OPL6_OP3DIR] = 0b00001000,

	[OPL7_OP1REG] = 0b01000000,
	[OPL7_OP1DIR] = 0b10000000,
	[OPL7_OP2REG] = 0b00010000,
	[OPL7_OP2DIR] = 0b00100000,
	[OPL7_OP3REG] = 0b00000100,
	[OPL7_OP3DIR] = 0b00001000,

	[OPL8_OP1REG] = 0b01000000,
	[OPL8_OP1DIR] = 0b10000000,
	[OPL8_OP2REG] = 0b00010000,
	[OPL8_OP2DIR] = 0b00100000,
	[OPL8_OP3REG] = 0b00000100,
	[OPL8_OP3DIR] = 0b00001000,
};

static int8_t				g_neg_state[STATE_END] = {
	[OPL1_OP1NEG] = 1,
	[OPL1_OP2NEG] = 1,
	[OPL3_OP1NEG] = 1,
	[OPL3_OP2NEG] = 1,
	[OPL4_OP1NEG] = 1,
	[OPL5_OP1NEG] = 1,
	[OPL6_OP2NEG] = 1,
	[OPL7_OP2NEG] = 1,
	[OPL7_OP3NEG] = 1,
};

static t_opcode				g_opcode_by_state[STATE_END] = {
	[LIVE_FOUND] = OP_LIVE,
	[LD_FOUND] = OP_LD,
	[ST_FOUND] = OP_ST,
	[ADD_FOUND] = OP_ADD,
	[SUB_FOUND] = OP_SUB,
	[AND_FOUND] = OP_AND,
	[OR_FOUND] = OP_OR,
	[XOR_FOUND] = OP_XOR,
	[ZJMP_FOUND] = OP_ZJMP,
	[LDI_FOUND] = OP_LDI,
	[STI_FOUND] = OP_STI,
	[FORK_FOUND] = OP_FORK,
	[LLD_FOUND] = OP_LLD,
	[LLDI_FOUND] = OP_LLDI,
	[LFORK_FOUND] = OP_LFORK,
	[AFF_FOUND] = OP_AFF,
};

static int					g_operand_to_mask_after[STATE_END] = {
	[OPL1_OP1D] = 1,
	[OPL1_OP1LABEL] = 1,
	[OPL1_OP2D] = 2,
	[OPL1_OP2LABEL] = 2,
	[OPL1_OP3D] = 3,
	[OPL1_OP3LABEL] = 3,

	[OPL2_OP1D] = 1,
	[OPL2_OP1LABEL] = 1,
	[OPL2_OP2D] = 2,
	[OPL2_OP2LABEL] = 2,
	[OPL2_OP3D] = 3,
	[OPL2_OP3LABEL] = 3,

	[OPL3_OP1D] = 1,
	[OPL3_OP1LABEL] = 1,
	[OPL3_OP2D] = 2,
	[OPL3_OP2LABEL] = 2,
	[OPL3_OP3D] = 3,
	[OPL3_OP3LABEL] = 3,

	[OPL4_OP1D] = 1,
	[OPL4_OP1LABEL] = 1,
	[OPL4_OP2D] = 2,
	[OPL4_OP2LABEL] = 2,
	[OPL4_OP3D] = 3,
	[OPL4_OP3LABEL] = 3,

	[OPL5_OP1D] = 1,
	[OPL5_OP1LABEL] = 1,
	[OPL5_OP2D] = 2,
	[OPL5_OP2LABEL] = 2,
	[OPL5_OP3D] = 3,
	[OPL5_OP3LABEL] = 3,

	[OPL6_OP1D] = 1,
	[OPL6_OP1LABEL] = 1,
	[OPL6_OP2D] = 2,
	[OPL6_OP2LABEL] = 2,
	[OPL6_OP3D] = 3,
	[OPL6_OP3LABEL] = 3,

	[OPL7_OP1D] = 1,
	[OPL7_OP1LABEL] = 1,
	[OPL7_OP2D] = 2,
	[OPL7_OP2LABEL] = 2,
	[OPL7_OP3D] = 3,
	[OPL7_OP3LABEL] = 3,

	[OPL8_OP1D] = 1,
	[OPL8_OP1LABEL] = 1,
	[OPL8_OP2D] = 2,
	[OPL8_OP2LABEL] = 2,
	[OPL8_OP3D] = 3,
	[OPL8_OP3LABEL] = 3,
};

static int					g_operand_to_fill[STATE_END] = {
	[OPL1_OP1D] = 1,
	[OPL1_OP2D] = 2,
	[OPL1_OP3D] = 3,

	[OPL2_OP1D] = 1,
	[OPL2_OP2D] = 2,
	[OPL2_OP3D] = 3,

	[OPL3_OP1D] = 1,
	[OPL3_OP2D] = 2,
	[OPL3_OP3D] = 3,

	[OPL4_OP1D] = 1,
	[OPL4_OP2D] = 2,
	[OPL4_OP3D] = 3,

	[OPL5_OP1D] = 1,
	[OPL5_OP2D] = 2,
	[OPL5_OP3D] = 3,

	[OPL6_OP1D] = 1,
	[OPL6_OP2D] = 2,
	[OPL6_OP3D] = 3,

	[OPL7_OP1D] = 1,
	[OPL7_OP2D] = 2,
	[OPL7_OP3D] = 3,

	[OPL8_OP1D] = 1,
	[OPL8_OP2D] = 2,
	[OPL8_OP3D] = 3,
};

static int						g_is_label_use_state[STATE_END] = {
	[OPL1_OP1LABEL] = 1,
	[OPL1_OP2LABEL] = 1,
	[OPL1_OP3LABEL] = 1,
	[OPL2_OP1LABEL] = 1,
	[OPL2_OP2LABEL] = 1,
	[OPL2_OP3LABEL] = 1,
	[OPL3_OP1LABEL] = 1,
	[OPL3_OP2LABEL] = 1,
	[OPL3_OP3LABEL] = 1,
	[OPL4_OP1LABEL] = 1,
	[OPL4_OP2LABEL] = 1,
	[OPL4_OP3LABEL] = 1,
	[OPL5_OP1LABEL] = 1,
	[OPL5_OP2LABEL] = 1,
	[OPL5_OP3LABEL] = 1,
	[OPL6_OP1LABEL] = 1,
	[OPL6_OP2LABEL] = 1,
	[OPL6_OP3LABEL] = 1,
	[OPL7_OP1LABEL] = 1,
	[OPL7_OP2LABEL] = 1,
	[OPL7_OP3LABEL] = 1,
	[OPL8_OP1LABEL] = 1,
	[OPL8_OP2LABEL] = 1,
	[OPL8_OP3LABEL] = 1,
};

uint8_t						g_fill_mod[4] = {
	[1] = 0b11000000,
	[2] = 0b11110000,
	[3] = 0b11111100,
};

static t_op					g_op_by_code[256] = {
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

static inline void			define_label_and_instruction(
	t_state new_state)
{
	if (g_is_label_use_state[g_asm.state] && !g_is_label_use_state[new_state] &&
		(g_asm.has_operand = 1))
		save_label((char *)g_label_ptr, (char *)g_line_ptr, 0);
	if (LABEL_CHAR == *g_line_ptr)
		g_is_label_use_state[new_state] ? (g_label_ptr = g_line_ptr + 1) :
			save_label((char *)g_line, (char *)g_line_ptr, 1);
	if (g_neg_state[new_state])
		g_asm.sign = -1;
	if (*g_line_ptr == ',')
		g_asm.sign = 1;
	if (g_opcode_by_state[new_state])
		g_asm.opcode = (uint8_t)g_opcode_by_state[new_state];
	if (g_mod_mask[new_state])
		g_asm.mod.value = (g_asm.mod.value & g_mod_mask[new_state]) |
			g_mod_set[new_state];
	if (g_asm.opcode && g_operand_to_mask_after[new_state] ==
		g_op_by_code[g_asm.opcode].op_count && (g_asm.has_operand = 1))
		g_asm.mod.value &= g_fill_mod[g_operand_to_mask_after[new_state]];
	if (g_operand_to_fill[new_state])
		g_asm.operands[g_operand_to_fill[new_state] - 1] = 10 *
			g_asm.operands[g_operand_to_fill[new_state] - 1] +
			(*g_line_ptr - '0') * g_asm.sign;
}

static inline void			write_instruction(void)
{
	g_written += write_be(g_fd_tmp, &g_asm.opcode, 1);
	if (g_op_by_code[g_asm.opcode].uses_mod_byte)
		g_written += write_be(g_fd_tmp, &g_asm.mod, 1);
	g_written += write_be(g_fd_tmp, &g_asm.operands[0],
		g_op_size[g_asm.opcode][g_asm.mod.flags.o1]);
	if (g_op_by_code[g_asm.opcode].op_count > 1)
		g_written += write_be(g_fd_tmp, &g_asm.operands[1],
			g_op_size[g_asm.opcode][g_asm.mod.flags.o2]);
	if (g_op_by_code[g_asm.opcode].op_count > 2)
		g_written += write_be(g_fd_tmp, &g_asm.operands[2],
			g_op_size[g_asm.opcode][g_asm.mod.flags.o3]);
	g_asm = g_init_asm;
	g_asm.mod.value = 0b11111100;
	g_asm.state = STALINE;
	g_asm.sign = 1;
	g_asm.has_operand = 0;
}

static int					g_header_state[STATE_END] = {
	[NAME_FOUND] = 1,
	[COMMENT_FOUND] = 1,
};

static size_t				g_header_sizes[STATE_END] = {
	[NAME_FOUND] = PROG_NAME_LENGTH,
	[COMMENT_FOUND] = COMMENT_LENGTH,
};

static int					g_name_filled;
static int					g_comment_filled;

static inline void			fill_header(
	t_state new_state)
{
	static int				i = 0;

	if (new_state == NAME_FOUND)
		g_name_filled = 1;
	if (new_state == COMMENT_FOUND)
		g_comment_filled = 1;
	if (g_header_state[g_asm.state] && g_header_state[new_state])
	{
		if (new_state == NAME_FOUND && (g_name_filled = 1))
			g_header.prog_name[i] = *g_line_ptr;
		else
			g_header.comment[i] = *g_line_ptr;
		if ((size_t)i < g_header_sizes[new_state] - 1)
			i = i + 1;
		else
			i = 0;
	}
	else
		i = 0;
}

static inline void			asm_loop_loop(
	t_state *new_state)
{
	if (*g_line_ptr > 127)
		exit(error_message_with_char(ERROR_SYNTAX_AT, *g_line_ptr));
	'\n' == *g_line_ptr ? ++g_line_i + (g_char_i = 0) : ++g_char_i;
	*new_state = get_new_state();
	fill_header(*new_state);
	define_label_and_instruction(*new_state);
	if (STALINE == *new_state && g_asm.opcode && g_asm.has_operand)
		write_instruction();
	g_asm.state = *new_state;
	if (STALINE == *new_state)
		g_label_ptr = (uint8_t *)g_line;
	g_line_ptr = STALINE == *new_state ? (uint8_t *)g_line : g_line_ptr + 1;
	if (MAX_LINE_SIZE == ((void *)g_line_ptr - (void *)g_line))
		exit(write(2, ERROR_LINE_TOO_LONG, sizeof(ERROR_LINE_TOO_LONG)));
}

void						asm_loop(void)
{
	t_state					new_state;

	g_asm = g_init_asm;
	g_asm.state = STALINE;
	g_asm.sign = 1;
	g_asm.mod.value = 0b11111100;
	g_line_ptr = (uint8_t *)g_line;
	g_line_i = 0;
	while (0 < read(g_fd_s, g_line_ptr, 1))
		asm_loop_loop(&new_state);
	if (!g_name_filled || !g_comment_filled)
		exit(write(2, ERROR_MISSING_HEADER, sizeof(ERROR_MISSING_HEADER)));
}
