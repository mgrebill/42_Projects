/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 07:47:27 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/03 07:47:28 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <termios.h>

static struct termios				g_new_term;

static char							g_corewar_figlet[] =
"  ____ ___  ____  _______        ___    ____  "
" / ___/ _ \\|  _ \\| ____\\ \\      / / \\  |  _ \\ "
"| |  | | | | |_) |  _|  \\ \\ /\\ / / _ \\ | |_) |"
"| |__| |_| |  _ <| |___  \\ V  V / ___ \\|  _ < "
" \\____\\___/|_| \\_\\_____|  \\_/\\_/_/   \\_\\_| \\_\\";

static char							g_credits_figlet[] =
" _             ____  __  __                             "
"  __  __ ____                _                       __ "
"    ______      _   _ _                     _   __  __  "
"____          _     _ _ _   "
"| |__  _   _  / ___||  \\/  | ___  _ __ ___ _ __   ___  "
"  |  \\/  |  _ \\ ___ _ __ ___ | |__  _   _ ___  ___    "
"\\ \\   / /  _ \\ ___| |_(_) |_    __ _ _ __   __| | |  "
"\\/  |/ ___|_ __ ___| |__ (_) | |  "
"| '_ \\| | | | \\___ \\| |\\/| |/ _ \\| '__/ _ \\ '_ \\ "
"/ _ \\   | |\\/| | |_) / _ \\ '_ ` _ \\| '_ \\| | | / __"
"|/ __|    \\ \\ / /| |_) / _ \\ __| | __|  / _` | '_ \\ "
"/ _` | | |\\/| | |  _| '__/ _ \\ '_ \\| | | |  "
"| |_) | |_| |  ___) | |  | | (_) | | |  __/ | | | (_) | "
" | |  | |  _ <  __/ | | | | | |_) | |_| \\__ \\ (__ _   "
" \\ V / |  __/  __/ |_| | |_  | (_| | | | | (_| | | |  |"
" | |_| | | |  __/ |_) | | | |_ "
"|_.__/ \\__, | |____/|_|  |_|\\___/|_|  \\___|_| |_|\\__"
"_( ) |_|  |_|_| \\_\\___|_| |_| |_|_.__/ \\__,_|___/\\__"
"_( )    \\_/  |_|   \\___|\\__|_|\\__|  \\__,_|_| |_|\\_"
"_,_| |_|  |_|\\____|_|  \\___|_.__/|_|_|_(_)"
"       |___/                                         |/ "
"                                                 |/     "
"                                                        "
"                            ";

static inline void					print_figlet(
	char *figlet,
	uint16_t x,
	uint16_t y,
	uint16_t width)
{
	int		i;

	set_cursor(x, y);
	i = 0;
	while (figlet[i])
	{
		write(1, figlet + i, 1);
		++i;
		if (i && !(i % width))
			set_cursor_new_line(x);
	}
	set_cursor(999, 999);
}

static inline void					print_box(
	uint16_t x,
	uint16_t y,
	uint16_t size_x,
	uint16_t size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	set_cursor(x, y);
	write(1, "╔", 3);
	while (i++ < size_x - 2)
		write(1, "═", 3);
	write(1, "╗", 4);
	set_cursor_new_line(x);
	while (j++ < size_y - 2)
	{
		i = 0;
		write(1, "║", 3);
		while (i++ < size_x - 2)
			write(1, " ", 1);
		write(1, "║", 3);
		set_cursor_new_line(x);
	}
	write(1, "╚", 3);
	i = 0;
	while (i++ < size_x - 2)
		write(1, "═", 3);
	write(1, "╝", 3);
}

static inline void					print_center(
	const char *const restrict text,
	const uint16_t x,
	const uint16_t y)
{
	int								size;

	size = 0;
	while (text[size])
		++size;
	set_cursor(x - size / 2, y);
	write(1, text, size);
}

static inline void					init_bars_and_chats_and_console(void)
{
	int								i;

	print_center("LIVES", 322, 38);
	print_box(LIVE_BAR_POS_X, LIVE_BAR_POS_Y, LIVE_BAR_WIDTH, 3);
	i = 0;
	while (i < g_champ_index - 1)
	{
		print_center(g_champs[i + 1].header.prog_name, 322,
			LIVE_BAR_POS_Y + (LIVE_BAR_HEIGHT + LIVE_BAR_SPACE) - 1 +
			i * (LIVE_BAR_HEIGHT + LIVE_BAR_SPACE));
		print_box(LIVE_BAR_POS_X,
			LIVE_BAR_POS_Y + (LIVE_BAR_HEIGHT + LIVE_BAR_SPACE) +
			i * (LIVE_BAR_HEIGHT + LIVE_BAR_SPACE),
			LIVE_BAR_WIDTH, LIVE_BAR_HEIGHT);
		print_box(CHAR_BOX_POS_X, CHAR_BOX_POS_Y + i *
			(CHAT_BOX_SPACE + CHAT_BOX_HEIGHT),
			CHAT_BOX_WIDTH, CHAT_BOX_HEIGHT);
		print_left(g_champs[i + 1].header.prog_name,
			CHAR_BOX_POS_X + 1, CHAR_BOX_POS_Y + 1 + i *
			(CHAT_BOX_SPACE + CHAT_BOX_HEIGHT));
		write(1, " says :", sizeof(" says :"));
		++i;
	}
	print_center("console :", 322, CONSOLE_POS_Y - 1);
	print_box(CONSOLE_POS_X, CONSOLE_POS_Y, CONSOLE_WIDTH, CONSOLE_HEIGHT + 2);
}

void								init_print(void)
{
	tcgetattr(STDIN_FILENO, &g_old_term);
	g_new_term = g_old_term;
	g_new_term.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_new_term);
	write(1, HIDE_CURSOR, sizeof(HIDE_CURSOR) - 1);
	write(1, CLEAR_DISPLAY, sizeof(CLEAR_DISPLAY) - 1);
	print_box(1, 1, 364, 18);
	print_box(1, 19, 83, 66);
	print_box(85, 19, 195, 66);
	print_box(281, 19, 84, 66);
	print_figlet(g_corewar_figlet, 160, 3, 46);
	print_figlet(g_credits_figlet, 86, 10, 196);
	print_shared_memory(g_shared_memory, X_MEM, Y_MEM, 0);
	set_cursor(288, 22);
	write(1, GRAPH_CYCLE, sizeof(GRAPH_CYCLE) - 1);
	set_cursor(288, 25);
	write(1, GRAPH_CYCLE_DIE, sizeof(GRAPH_CYCLE_DIE) - 1);
	set_cursor(288, 28);
	write(1, GRAPH_DELTA, sizeof(GRAPH_DELTA) - 1);
	set_cursor(288, 31);
	write(1, GRAPH_CHECKS, sizeof(GRAPH_CHECKS) - 1);
	set_cursor(288, 34);
	write(1, GRAPH_NB_PROC, sizeof(GRAPH_NB_PROC) - 1);
	init_bars_and_chats_and_console();
	set_cursor(999, 999);
}
