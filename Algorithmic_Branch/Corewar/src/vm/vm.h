/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:23:14 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 16:23:16 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "../corewar.h"

# define MESSAGE_DUP				"System dumped at cycle "
# define MSG_NO_WINNER_P1			"Les joueurs sont donc des losers "
# define MSG_NO_WINNER_P2			"qui ne vivent pas.\n"
# define MSG_NO_WINNER				(MSG_NO_WINNER_P1 MSG_NO_WINNER_P2)
# define MESSAGE_THANKS				"Thanks for playing !\n"
# define MESSAGE_QUIT				"Press return to quit.\n"
# define MAX_FLAGS					4
# define FLAG_CHAMP_NUM				0
# define FLAG_DUP					1
# define FLAG_GRAPHICS				2
# define MEM_SIZE					(1024 * 4)
# define RESET_FORMAT				"\033[0m"
# define SHOW_CURSOR				"\033[?25h"
# define SET_BOLD					"\033[1m"
# define HIDE_CURSOR				"\033[?25l"
# define CLEAR_DISPLAY				"\033[2J"
# define BYTES_PER_ROW				64
# define BOX_HEIGHT					MEM_SIZE / BYTES_PER_ROW + 3
# define BOX_WIDTH					BYTES_PER_ROW * 3 + 2
# define RESET_FORMAT				"\033[0m"
# define SET_BOLD					"\033[1m"
# define X_MEM						87
# define Y_MEM						20
# define CHAT_BOX_WIDTH				80
# define CHAT_BOX_HEIGHT			16
# define CHAR_BOX_POS_X				2
# define CHAR_BOX_POS_Y				20
# define CHAT_BOX_SPACE				0
# define LIVE_BAR_WIDTH				77
# define LIVE_BAR_HEIGHT			3
# define LIVE_BAR_POS_X				284
# define LIVE_BAR_POS_Y				40
# define LIVE_BAR_SPACE				3
# define CONSOLE_POS_X				284
# define CONSOLE_POS_Y				70
# define CONSOLE_WIDTH				77
# define CONSOLE_HEIGHT				12
# define GRAPH_CYCLE				"cycles : "
# define GRAPH_CYCLE_DIE			"cycles to die : "
# define GRAPH_DELTA				"cycles delta : "
# define GRAPH_CHECKS				"checks : "
# define GRAPH_NB_PROC				"number of processes : "

typedef	struct						s_champ
{
	t_header						header;
	uint64_t						pid;
	uint8_t							color_id;
	uint8_t							buffer_code[CHAMP_MAX_SIZE];
}									t_champ;

typedef struct s_process			t_process;

struct								s_process
{
	t_champ							*creator;
	t_process						*previous;
	t_process						*next;
	struct
	{
		t_reg_type					r[REG_NUMBER];
	}								registers;
	uint64_t						id;
	uint16_t						ip;
	uint16_t						next_ip;
	uint8_t							zero_flag:1;
	uint8_t							alive:1;
	uint8_t							made_live:1;
	t_reg_type						o[3];
	t_reg_type						*dest;
	uint8_t							opcode;
	uint8_t							mod_byte;
	uint64_t						cycle_left;
	uint16_t						ip_last_live;
};

typedef struct						s_vm
{
	t_process						*last_process;
	size_t							next_free_process;
	size_t							process_number;
	t_champ							*last_man_standing;
	uint32_t						nbr_live;
	uint32_t						nbr_checks;
	uint8_t							nb_champs;
}									t_vm;

extern char							g_color_by_pid[8][5];
extern char							g_background_by_pid[8][5];

extern int64_t						g_abstract_cycle_to_die;
extern int64_t						g_concrete_cycle_to_die;

extern uint8_t						g_shared_memory[MEM_SIZE];
extern uint8_t						g_pid_memory[MEM_SIZE];

extern t_vm							g_vm;
extern int							g_flags[MAX_FLAGS];
extern int							g_flag_nbrs[MAX_FLAGS];
extern uint8_t						g_champ_index;
extern t_champ						g_champs[MAX_PLAYERS + 1];
extern struct termios				g_old_term;

void								iprint_nbr(
	uint64_t nbr);
void								print_aff(
	const t_reg_type color_id,
	const char c);
void								reset_process_live(void);
uint16_t							print_live(
	const t_reg_type color_id,
	const uint16_t ip,
	const uint16_t ip_last_live);
uint32_t							reverse32(
	const uint32_t a);
void								initialize_battlefied(void);
t_process							*allocate_process(void);
void								init_free_processes_stack(void);
void								fork_process(
	const t_process *const restrict process_to_fork,
	const t_reg_type next_ip);
void								kill_obsolete_process(
	t_process *cur_process);
int16_t								calc_absolute_addr(
	const int16_t offset,
	const t_process *const restrict cur_process);
size_t								mem_cp_endianness(
	void *const dst,
	void *const src,
	const size_t size,
	const uint8_t color_id);
void								process_loop(void);
void								load_instruction(
	t_process *cur_process);
void								load_argv(
	const int argc,
	const char *const restrict *const restrict argv);
int									load_champ(
	const char *const restrict name,
	const uint8_t pid);
void								print_shared_memory(
	const uint8_t *const restrict memory,
	int x,
	int y,
	int dump);
void								update_corewar(
	const uint8_t *const memory,
	uint8_t *slot,
	size_t size,
	uint8_t color);
void								init_print(void);
void								print_nbr_base(
	uint64_t nbr,
	uint8_t base);
void								print_winner_graphics(void);
void								check_situation(int64_t cycle);
void								print_ip(
	const uint8_t *const memory,
	uint8_t *slot,
	uint8_t print);
int									iprint(
	const int fd,
	const char *const restrict src,
	const size_t size);
void								print_winner(void);
void								init_print(void);
void								set_cursor(
	const uint16_t x,
	const uint16_t y);
void								set_cursor_new_line(
	const uint16_t x);
int									print_left(
	const char *const restrict text,
	const uint16_t x,
	const uint16_t y);

#endif
