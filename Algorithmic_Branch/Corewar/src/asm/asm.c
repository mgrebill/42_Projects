/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:28:41 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 17:28:42 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm								g_asm;
int									g_fd_s;
int									g_fd_tmp;
uint8_t								*g_line_ptr;
uint8_t								*g_label_ptr;
char								g_line[MAX_LINE_SIZE];
char								g_cor_name[COR_NAME_SIZE];

int									g_autorized_end[STATE_END] = {
	[STALINE] = 1,
	[OPL1_OP3LABEL] = 1,
	[OPL1_OP3EB] = 1,
	[OPL1_OP3D] = 1,
	[OPL2_OP3LABEL] = 1,
	[OPL2_OP3EB] = 1,
	[OPL2_OP3D] = 1,
	[OPL3_OP3LABEL] = 1,
	[OPL3_OP3D] = 1,
	[OPL3_OP3EB] = 1,
	[OPL4_OP1LABEL] = 1,
	[OPL4_OP1D] = 1,
	[OPL4_OP1EB] = 1,
	[OPL5_OP2EB] = 1,
	[OPL5_OP2D] = 1,
	[OPL6_OP2LABEL] = 1,
	[OPL6_OP2EB] = 1,
	[OPL6_OP2D] = 1,
	[OPL7_OP3LABEL] = 1,
	[OPL7_OP3EB] = 1,
	[OPL7_OP3D] = 1,
	[OPL8_OP1LABEL] = 1,
	[OPL8_OP1EB] = 1,
	[OPL8_OP1D] = 1,
};

size_t								g_op_size[256][4] = {
	[0][REG_MOD] = 0,
	[0][IND_MOD] = 0,
	[0][DIR_MOD] = 0,
	[OP_LIVE][REG_MOD] = REG_ID_SIZE,
	[OP_LIVE][IND_MOD] = IND_SIZE,
	[OP_LIVE][DIR_MOD] = REG_SIZE,
	[OP_LD][REG_MOD] = REG_ID_SIZE,
	[OP_LD][IND_MOD] = IND_SIZE,
	[OP_LD][DIR_MOD] = REG_SIZE,
	[OP_ST][REG_MOD] = REG_ID_SIZE,
	[OP_ST][IND_MOD] = IND_SIZE,
	[OP_ST][DIR_MOD] = REG_SIZE,
	[OP_ADD][REG_MOD] = REG_ID_SIZE,
	[OP_ADD][IND_MOD] = IND_SIZE,
	[OP_ADD][DIR_MOD] = REG_SIZE,
	[OP_SUB][REG_MOD] = REG_ID_SIZE,
	[OP_SUB][IND_MOD] = IND_SIZE,
	[OP_SUB][DIR_MOD] = REG_SIZE,
	[OP_AND][REG_MOD] = REG_ID_SIZE,
	[OP_AND][IND_MOD] = IND_SIZE,
	[OP_AND][DIR_MOD] = REG_SIZE,
	[OP_OR][REG_MOD] = REG_ID_SIZE,
	[OP_OR][IND_MOD] = IND_SIZE,
	[OP_OR][DIR_MOD] = REG_SIZE,
	[OP_XOR][REG_MOD] = REG_ID_SIZE,
	[OP_XOR][IND_MOD] = IND_SIZE,
	[OP_XOR][DIR_MOD] = REG_SIZE,
	[OP_ZJMP][REG_MOD] = REG_ID_SIZE,
	[OP_ZJMP][IND_MOD] = IND_SIZE,
	[OP_ZJMP][DIR_MOD] = IND_SIZE,
	[OP_LDI][REG_MOD] = REG_ID_SIZE,
	[OP_LDI][IND_MOD] = IND_SIZE,
	[OP_LDI][DIR_MOD] = IND_SIZE,
	[OP_STI][REG_MOD] = REG_ID_SIZE,
	[OP_STI][IND_MOD] = IND_SIZE,
	[OP_STI][DIR_MOD] = IND_SIZE,
	[OP_FORK][REG_MOD] = REG_ID_SIZE,
	[OP_FORK][IND_MOD] = IND_SIZE,
	[OP_FORK][DIR_MOD] = IND_SIZE,
	[OP_LLD][REG_MOD] = REG_ID_SIZE,
	[OP_LLD][IND_MOD] = IND_SIZE,
	[OP_LLD][DIR_MOD] = REG_SIZE,
	[OP_LLDI][REG_MOD] = REG_ID_SIZE,
	[OP_LLDI][IND_MOD] = IND_SIZE,
	[OP_LLDI][DIR_MOD] = IND_SIZE,
	[OP_LFORK][REG_MOD] = REG_ID_SIZE,
	[OP_LFORK][IND_MOD] = IND_SIZE,
	[OP_LFORK][DIR_MOD] = IND_SIZE,
	[OP_AFF][REG_MOD] = REG_ID_SIZE,
	[OP_AFF][IND_MOD] = IND_SIZE,
	[OP_AFF][DIR_MOD] = REG_SIZE,
};

static inline uint32_t				reverse32(
	const uint32_t a)
{
	return ((a >> 24) + (a << 24) +
		((a >> 8) & 0xFF00) + ((a << 8) & 0xFF0000));
}

static inline void					link_file(
	const int g_fd_tmp, const char *name)
{
	int								fd_cor;
	char							tmp;

	link_labels();
	g_header.magic = reverse32(COREWAR_EXEC_MAGIC);
	g_header.prog_size = reverse32(g_written);
	lseek(g_fd_tmp, 0, SEEK_SET);
	if (0 > (fd_cor = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777)))
		exit(write(1, ERROR_INVALID_OUTPUT, sizeof(ERROR_INVALID_OUTPUT) - 1));
	write(fd_cor, &g_header, sizeof(g_header));
	while (1 == read(g_fd_tmp, &tmp, 1))
		write(fd_cor, &tmp, 1);
	close(g_fd_tmp);
	close(fd_cor);
	write(1, MESSAGE_SUCCESS, sizeof(MESSAGE_SUCCESS));
}

static inline void					init_files(
	const char *const restrict name)
{
	int								e;
	int								u;

	if (0 > (g_fd_s = open(name, O_RDONLY, 0)))
		exit(write(1, ERROR_INVALID_INPUT, sizeof(ERROR_INVALID_INPUT) - 1));
	e = -1;
	u = -1;
	while (COR_NAME_SIZE > (e + u + 1) &&
		((name[e + 1] && (++e || e == 0)) ||
			("cor"[u + 1] && (++u || u == 0))))
		g_cor_name[e + u + 1] = name[e + 1] ? name[e] : "cor"[u + 1];
	if (0 > (g_fd_tmp = open("/tmp/tmp.cor", O_CREAT | O_RDWR | O_TRUNC, 0777)))
		exit(write(1, ERROR_NO_TMP, sizeof(ERROR_NO_TMP) - 1));
}

int									main(
	int argc,
	char **argv)
{
	if (argc < 2)
		exit(write(2, ERROR_NB_ARGS, sizeof(ERROR_NB_ARGS) - 1));
	load_label_transitions();
	init_files(argv[1]);
	asm_loop();
	if (g_autorized_end[g_asm.state])
		link_file(g_fd_tmp, g_cor_name);
	else
		exit(write(2, ERROR_UNEXPECTED_EOF, sizeof(ERROR_UNEXPECTED_EOF) - 1));
}
