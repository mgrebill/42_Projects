/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:26:16 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 17:26:16 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_label_state			g_label_transitions[256][MAX_LABEL_STATE];
static t_label_pos				g_label_def[MAX_LABEL];
static t_label_use				g_label_use[MAX_LABEL * MAX_USE_BY_LABEL];
static t_label_id				g_label_id_by_state[MAX_LABEL];
static char						g_label_name_by_id[LABEL_STRING_SIZE]
[MAX_LABEL];

static size_t					g_op_mod_size[STATE_END] = {
	[OPL1_OP1LABEL] = 2,
	[OPL1_OP2LABEL] = 2,
	[OPL1_OP3LABEL] = 2,

	[OPL2_OP1LABEL] = 2,
	[OPL2_OP2LABEL] = 2,
	[OPL2_OP3LABEL] = 2,

	[OPL3_OP1LABEL] = 2,
	[OPL3_OP2LABEL] = 2,
	[OPL3_OP3LABEL] = 2,

	[OPL4_OP1LABEL] = 1,
	[OPL4_OP2LABEL] = 1,
	[OPL4_OP3LABEL] = 1,

	[OPL5_OP1LABEL] = 2,
	[OPL5_OP2LABEL] = 2,
	[OPL5_OP3LABEL] = 2,

	[OPL6_OP1LABEL] = 2,
	[OPL6_OP2LABEL] = 2,
	[OPL6_OP3LABEL] = 2,

	[OPL7_OP1LABEL] = 2,
	[OPL7_OP2LABEL] = 2,
	[OPL7_OP3LABEL] = 2,

	[OPL8_OP1LABEL] = 2,
	[OPL8_OP2LABEL] = 2,
	[OPL8_OP3LABEL] = 2,

};

static int						g_label_operand_id[STATE_END] = {
	[OPL1_OP1LABEL] = 1,
	[OPL1_OP2LABEL] = 2,
	[OPL1_OP3LABEL] = 3,

	[OPL2_OP1LABEL] = 1,
	[OPL2_OP2LABEL] = 2,
	[OPL2_OP3LABEL] = 3,

	[OPL3_OP1LABEL] = 1,
	[OPL3_OP2LABEL] = 2,
	[OPL3_OP3LABEL] = 3,

	[OPL4_OP1LABEL] = 1,
	[OPL4_OP2LABEL] = 2,
	[OPL4_OP3LABEL] = 3,

	[OPL5_OP1LABEL] = 1,
	[OPL5_OP2LABEL] = 2,
	[OPL5_OP3LABEL] = 3,

	[OPL6_OP1LABEL] = 1,
	[OPL6_OP2LABEL] = 2,
	[OPL6_OP3LABEL] = 3,

	[OPL7_OP1LABEL] = 1,
	[OPL7_OP2LABEL] = 2,
	[OPL7_OP3LABEL] = 3,

	[OPL8_OP1LABEL] = 1,
	[OPL8_OP2LABEL] = 2,
	[OPL8_OP3LABEL] = 3,
};

extern	t_state					g_transitions[256][STATE_END];

static inline t_label_state		get_label_state(
	const char *input,
	const char *input_end)
{
	static t_label_state		free_state = INITIAL_LABEL_STATE + 1;
	t_label_state				new_state;
	t_label_state				state;

	state = INITIAL_LABEL_STATE;
	while (input != input_end)
	{
		if ((new_state = g_label_transitions[(int)*input][state]))
			state = new_state;
		else
		{
			g_label_transitions[(int)*input][state] = free_state;
			state = free_state++;
		}
		++input;
	}
	return (state);
}

static inline void				save_label_use(
	const char *input,
	const char *input_end,
	const t_label_pos pos,
	const t_label_state state)
{
	static int					use_index = 0;
	uint8_t						operand_type;
	int							i;

	operand_type = 3 &
		(g_asm.mod.value >> (8 - g_label_operand_id[g_asm.state] * 2));
	g_label_use[use_index].id = g_label_id_by_state[state];
	g_label_use[use_index].size = g_op_size[g_asm.opcode][operand_type];
	g_label_use[use_index].offset = g_op_mod_size[g_asm.state] +
						(g_label_operand_id[g_asm.state] > 1) *
						g_op_size[g_asm.opcode][g_asm.mod.flags.o1] +
						(g_label_operand_id[g_asm.state] > 2) *
						g_op_size[g_asm.opcode][g_asm.mod.flags.o2];
	g_label_use[use_index].pos = pos;
	i = 0;
	while (input != input_end && i < LABEL_STRING_SIZE)
		g_label_name_by_id[g_label_use[use_index].id][i++] = *input++;
	g_label_name_by_id[g_label_use[use_index].id][i] = 0;
	use_index++;
}

void							save_label(
	const char *input,
	const char *input_end,
	const int is_def)
{
	static t_label_id			unused_label_id = 1;
	t_label_state				state;
	t_label_pos					pos;

	state = get_label_state(input, input_end);
	pos = g_written +
		g_op_mod_size[g_asm.state] +
		(g_label_operand_id[g_asm.state] > 1) *
		g_op_size[g_asm.opcode][g_asm.mod.flags.o1] +
		(g_label_operand_id[g_asm.state] > 2) *
		g_op_size[g_asm.opcode][g_asm.mod.flags.o2];
	if (!g_label_id_by_state[state])
		g_label_id_by_state[state] = unused_label_id++;
	if (is_def)
		g_label_def[g_label_id_by_state[state]] = 1 + pos;
	else
		save_label_use(input, input_end, pos, state);
}

void							link_labels(void)
{
	int							i;
	int32_t						temp;

	i = 0;
	while (g_label_use[i].id)
	{
		if (!g_label_def[g_label_use[i].id])
			exit(error_message_with_string(
				ERROR_UNDEFINED_SYMBOL, g_label_name_by_id[g_label_use[i].id]));
		lseek(g_fd_tmp, g_label_use[i].pos, SEEK_SET);
		temp = g_label_def[g_label_use[i].id] - 1
			- g_label_use[i].pos + g_label_use[i].offset;
		write_be(g_fd_tmp, &temp, g_label_use[i].size);
		++i;
	}
}
