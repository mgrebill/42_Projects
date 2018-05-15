/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:45:04 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 15:45:12 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# define REG_ID_SIZE				1
# define IND_SIZE					2
# define REG_SIZE					sizeof(t_reg_type)
# define DIR_SIZE					REG_SIZE

# define REG_MOD					1
# define DIR_MOD					2
# define IND_MOD					3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE				(MEM_SIZE / 6)

# define REG_NUMBER					16

# define CYCLE_TO_DIE				1536
# define CYCLE_DELTA				50
# define NBR_LIVE					21
# define MAX_CHECKS					10

# define T_REG						1
# define T_DIR						2
# define T_IND						4
# define T_LAB						8

# define PROG_NAME_LENGTH			(128)
# define COMMENT_LENGTH				(2048)
# define COREWAR_EXEC_MAGIC			0xea83f3

# define IDX_MAX					(0x7FFF)
# define MAX_SIZE_OP				14
# define MAX_PROCESSES_NUMBER		100000
# define BITWISE_MASK				0xFFFFFFFF

# define INITIAL_LABEL_STATE		1
# define MAX_LABEL_STATE			10000
# define MAX_LABEL					1000
# define MAX_USE_BY_LABEL			10

# define CHAR_BLANK					' '
# define CHAR_DIGIT					'0'
# define COMMENT_CHAR				'#'
# define DIRECT_CHAR				'%'
# define LABEL_CHAR					':'
# define LINE_FEED					'\n'
# define NEG_CHAR					'-'
# define REGISTER_CHAR				'r'
# define SEPARATOR_CHAR				','
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING			".comment"
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define ERROR_INVALID_CHAMPION		"Error: invalid champion."
# define ERROR_MAX_CHAMPS			"Error: too many champions."
# define ERROR_NO_CHAMP				"Error: no champion found."
# define ERROR_USAGE1				"Usage: corewar [-g] [-dup <cycle_to_dump>]"
# define ERROR_USAGE2				" [-n <champ_number>] champion "
# define ERROR_USAGE3				"[[-n <champ_number>] champion] ...\n"
# define ERROR_USAGE				(ERROR_USAGE1 ERROR_USAGE2 ERROR_USAGE3)

typedef int32_t						t_reg_type;

typedef char						t_arg_type;

typedef int							t_label_id;

typedef uint32_t					t_label_pos;

typedef int							t_label_state;

typedef	int64_t						t_operand;

typedef	enum						e_opcode
{
	OP_LIVE = 1,
	OP_LD,
	OP_ST,
	OP_ADD,
	OP_SUB,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_ZJMP,
	OP_LDI,
	OP_STI,
	OP_FORK,
	OP_LLD,
	OP_LLDI,
	OP_LFORK,
	OP_AFF,
	OP_END,
}									t_opcode;

typedef	enum						e_state
{
	INITIAL_STATE = 1,

	DOT_BEFORE_HEADER_FOUND,
	DOT_N_FOUND,
	DOT_NA_FOUND,
	DOT_NAM_FOUND,
	DOT_NAME_FOUND,
	NAME_FOUND,
	NAME_COMPLETED,
	DOT_BEFORE_COMMENT_FOUND,
	DOT_C_FOUND,
	DOT_CO_FOUND,
	DOT_COM_FOUND,
	DOT_COMM_FOUND,
	DOT_COMME_FOUND,
	DOT_COMMEN_FOUND,
	DOT_COMMENT_FOUND,
	COMMENT_FOUND,
	COMMENT_COMPLETED,
	STALINE,
	STACOM,
	LABEL_DEF,

	A_FOUND,
	F_FOUND,
	L_FOUND,
	O_FOUND,
	S_FOUND,
	X_FOUND,
	Z_FOUND,

	AD_FOUND,
	AF_FOUND,
	AN_FOUND,

	AFF_FOUND,

	ADD_FOUND,
	AND_FOUND,

	FO_FOUND,
	FOR_FOUND,
	FORK_FOUND,

	LD_FOUND,
	LDI_FOUND,

	LI_FOUND,
	LIV_FOUND,
	LIVE_FOUND,

	LF_FOUND,
	LFO_FOUND,
	LFOR_FOUND,
	LFORK_FOUND,

	LL_FOUND,
	LLD_FOUND,
	LLDI_FOUND,

	OR_FOUND,

	ST_FOUND,
	STI_FOUND,

	SU_FOUND,
	SUB_FOUND,

	XO_FOUND,
	XOR_FOUND,

	ZJ_FOUND,
	ZJM_FOUND,
	ZJMP_FOUND,

	OPL1,
	OPL1_OP1,
	OPL1_OP2,
	OPL1_OP3,
	OPL1_OP1LABEL,
	OPL1_OP2LABEL,
	OPL1_OP3LABEL,
	OPL1_OP1REG,
	OPL1_OP2REG,
	OPL1_OP3REG,
	OPL1_OP1DIR,
	OPL1_OP2DIR,
	OPL1_OP3DIR,
	OPL1_OP1NEG,
	OPL1_OP2NEG,
	OPL1_OP3NEG,
	OPL1_OP1D,
	OPL1_OP2D,
	OPL1_OP3D,
	OPL1_OP1EB,
	OPL1_OP2EB,
	OPL1_OP3EB,

	OPL2,
	OPL2_OP1,
	OPL2_OP2,
	OPL2_OP3,
	OPL2_OP1LABEL,
	OPL2_OP2LABEL,
	OPL2_OP3LABEL,
	OPL2_OP1REG,
	OPL2_OP2REG,
	OPL2_OP3REG,
	OPL2_OP1DIR,
	OPL2_OP2DIR,
	OPL2_OP3DIR,
	OPL2_OP1NEG,
	OPL2_OP2NEG,
	OPL2_OP3NEG,
	OPL2_OP1D,
	OPL2_OP2D,
	OPL2_OP3D,
	OPL2_OP1EB,
	OPL2_OP2EB,
	OPL2_OP3EB,

	OPL3,
	OPL3_OP1,
	OPL3_OP2,
	OPL3_OP3,
	OPL3_OP1LABEL,
	OPL3_OP2LABEL,
	OPL3_OP3LABEL,
	OPL3_OP1REG,
	OPL3_OP2REG,
	OPL3_OP3REG,
	OPL3_OP1DIR,
	OPL3_OP2DIR,
	OPL3_OP3DIR,
	OPL3_OP1NEG,
	OPL3_OP2NEG,
	OPL3_OP3NEG,
	OPL3_OP1D,
	OPL3_OP2D,
	OPL3_OP3D,
	OPL3_OP1EB,
	OPL3_OP2EB,
	OPL3_OP3EB,

	OPL4,
	OPL4_OP1,
	OPL4_OP2,
	OPL4_OP3,
	OPL4_OP1LABEL,
	OPL4_OP2LABEL,
	OPL4_OP3LABEL,
	OPL4_OP1REG,
	OPL4_OP2REG,
	OPL4_OP3REG,
	OPL4_OP1DIR,
	OPL4_OP2DIR,
	OPL4_OP3DIR,
	OPL4_OP1NEG,
	OPL4_OP2NEG,
	OPL4_OP3NEG,
	OPL4_OP1D,
	OPL4_OP2D,
	OPL4_OP3D,
	OPL4_OP1EB,
	OPL4_OP2EB,
	OPL4_OP3EB,

	OPL5,
	OPL5_OP1,
	OPL5_OP2,
	OPL5_OP3,
	OPL5_OP1LABEL,
	OPL5_OP2LABEL,
	OPL5_OP3LABEL,
	OPL5_OP1REG,
	OPL5_OP2REG,
	OPL5_OP3REG,
	OPL5_OP1DIR,
	OPL5_OP2DIR,
	OPL5_OP3DIR,
	OPL5_OP1NEG,
	OPL5_OP2NEG,
	OPL5_OP3NEG,
	OPL5_OP1D,
	OPL5_OP2D,
	OPL5_OP3D,
	OPL5_OP1EB,
	OPL5_OP2EB,
	OPL5_OP3EB,

	OPL6,
	OPL6_OP1,
	OPL6_OP2,
	OPL6_OP3,
	OPL6_OP1LABEL,
	OPL6_OP2LABEL,
	OPL6_OP3LABEL,
	OPL6_OP1REG,
	OPL6_OP2REG,
	OPL6_OP3REG,
	OPL6_OP1DIR,
	OPL6_OP2DIR,
	OPL6_OP3DIR,
	OPL6_OP1NEG,
	OPL6_OP2NEG,
	OPL6_OP3NEG,
	OPL6_OP1D,
	OPL6_OP2D,
	OPL6_OP3D,
	OPL6_OP1EB,
	OPL6_OP2EB,
	OPL6_OP3EB,

	OPL7,
	OPL7_OP1,
	OPL7_OP2,
	OPL7_OP3,
	OPL7_OP1LABEL,
	OPL7_OP2LABEL,
	OPL7_OP3LABEL,
	OPL7_OP1REG,
	OPL7_OP2REG,
	OPL7_OP3REG,
	OPL7_OP1DIR,
	OPL7_OP2DIR,
	OPL7_OP3DIR,
	OPL7_OP1NEG,
	OPL7_OP2NEG,
	OPL7_OP3NEG,
	OPL7_OP1D,
	OPL7_OP2D,
	OPL7_OP3D,
	OPL7_OP1EB,
	OPL7_OP2EB,
	OPL7_OP3EB,

	OPL8,
	OPL8_OP1,
	OPL8_OP2,
	OPL8_OP3,
	OPL8_OP1LABEL,
	OPL8_OP2LABEL,
	OPL8_OP3LABEL,
	OPL8_OP1REG,
	OPL8_OP2REG,
	OPL8_OP3REG,
	OPL8_OP1DIR,
	OPL8_OP2DIR,
	OPL8_OP3DIR,
	OPL8_OP1NEG,
	OPL8_OP2NEG,
	OPL8_OP3NEG,
	OPL8_OP1D,
	OPL8_OP2D,
	OPL8_OP3D,
	OPL8_OP1EB,
	OPL8_OP2EB,
	OPL8_OP3EB,

	STATE_END,
}									t_state;

typedef	struct						s_header
{
	unsigned int					magic;
	char							prog_name[PROG_NAME_LENGTH + 1];
	unsigned int					prog_size;
	char							comment[COMMENT_LENGTH + 1];
}									t_header;

typedef struct						s_label_use
{
	t_label_id						id;
	t_label_pos						pos;
	uint8_t							offset;
	size_t							size;
}									t_label_use;

typedef struct						s_mask
{
	t_reg_type						v;
	t_reg_type						and;
	t_reg_type						or;
	t_reg_type						xor;
}									t_mask;

typedef struct						s_op
{
	t_opcode						code;
	const char						*name;
	int								nbr_cycles;
	int								op_count;
	uint8_t							uses_mod_byte:1;
	uint8_t							addr:1;
}									t_op;

int									error_message_with_number(
	const char *const restrict msg,
	int nbr);

#endif
