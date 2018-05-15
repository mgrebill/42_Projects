/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:30:08 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 16:30:09 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdint.h>
# include "../corewar.h"

# define ERROR_LINE_TOO_LONG		"Error : line too long\n"
# define MESSAGE_SUCCESS			"Cor file written successfully !\n"
# define ERROR_MISSING_HEADER		"Error: Missing name or comment in header\n"
# define LABEL_STRING_SIZE			100
# define MAX_LINE_SIZE				10000
# define COR_NAME_SIZE				0x10000
# define ERROR_INVALID_INPUT		"Error: Invalid input file.\n"
# define ERROR_INVALID_OUTPUT		"Error: Invalid output file.\n"
# define ERROR_NO_TMP				"Error: Can't open temporary file.\n"
# define ERROR_NB_ARGS				"Not enough arguments\n"
# define ERROR_UNEXPECTED_EOF		"Unexpected end of file\n"
# define ERROR_UNDEFINED_SYMBOL		"Undefined symbol "
# define ERROR_SYNTAX_AT			"Syntax error at character "

typedef union						u_mod
{
	uint8_t							value;
	struct
	{
		uint8_t						padding:2;
		uint8_t						o3:2;
		uint8_t						o2:2;
		uint8_t						o1:2;
	}								flags;
}									t_mod;

typedef struct						s_asm
{
	t_state							state;
	uint8_t							opcode;
	t_mod							mod;
	t_operand						operands[3];
	t_operand						sign;
	int								has_operand;
}									t_asm;

size_t								g_written;
t_header							g_header;
t_asm								g_init_asm;

extern size_t						g_line_i;
extern size_t						g_char_i;
extern t_asm						g_asm;
extern int							g_fd_s;
extern int							g_fd_tmp;
extern uint8_t						*g_line_ptr;
extern uint8_t						*g_label_ptr;
extern char							g_line[MAX_LINE_SIZE];
extern size_t						g_op_size[256][4];
extern char							*g_state_strings[STATE_END];

int									error_message_with_char(
	const char *const restrict msg,
	const char c);
int									error_message_with_string(
	const char *const restrict msg,
	const char *const restrict str);
t_state								get_new_state(void);
void								link_labels(void);
void								save_label(
	const char *input,
	const char *input_end,
	const int is_def);
void								asm_loop(void);
void								load_label_transitions(void);
size_t								write_be(
	int fd,
	void *buff,
	size_t size);
#endif
