/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 07:51:02 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/03 07:51:02 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char								g_console_lines
[CONSOLE_HEIGHT][CONSOLE_WIDTH + 1] = {"$> "};
int									g_console_line_count = 1;
int									g_console_line_index;
int									g_console_char_index = 3;

static inline void					print_console(void)
{
	int								line_index;
	int								e;

	line_index = 0;
	while (line_index < g_console_line_count)
	{
		e = print_left(g_console_lines[(CONSOLE_HEIGHT + g_console_line_index -
			line_index) % CONSOLE_HEIGHT],
			CONSOLE_POS_X + 1,
			CONSOLE_POS_Y + 1 + g_console_line_count - 1 - line_index);
		while (e++ < CONSOLE_WIDTH - 2)
			write(1, " ", 1);
		++line_index;
	}
	e = 0;
	while (g_console_lines[g_console_line_index][e])
		++e;
	set_cursor(CONSOLE_POS_X + 1 + e,
		CONSOLE_POS_Y + 1 + g_console_line_count - 1);
	write(1, "\033[47m", 5);
	write(1, " ", 1);
	write(1, RESET_FORMAT, 4);
}

static inline void					print_console_line(
	const char *restrict line,
	size_t size)
{
	while (size--)
	{
		if ('\n' == *line || g_console_char_index == CONSOLE_WIDTH - 2)
		{
			g_console_lines[g_console_line_index][g_console_char_index] = 0;
			g_console_line_index = (g_console_line_index + 1) % CONSOLE_HEIGHT;
			g_console_char_index = 0;
			g_console_lines[g_console_line_index][g_console_char_index++] = '$';
			g_console_lines[g_console_line_index][g_console_char_index++] = '>';
			g_console_lines[g_console_line_index][g_console_char_index++] = ' ';
			g_console_lines[g_console_line_index][g_console_char_index] = 0;
			if (g_console_line_count != CONSOLE_HEIGHT)
				++g_console_line_count;
		}
		if ('\n' != *line)
		{
			g_console_lines[g_console_line_index]
				[g_console_char_index++] = *line;
			g_console_lines[g_console_line_index][g_console_char_index] = 0;
		}
		++line;
	}
	print_console();
	set_cursor(999, 999);
}

int									iprint(
	const int fd,
	const char *const restrict src,
	const size_t size)
{
	if (g_flags[FLAG_GRAPHICS])
		print_console_line(src, size);
	else
		return (write(fd, src, size));
	return (1);
}

void								iprint_nbr(
	uint64_t nbr)
{
	char							tab[23];
	int								i;

	i = 0;
	tab[i++] = nbr % 10 + '0';
	while ((nbr /= 10))
		tab[i++] = nbr % 10 + '0';
	while (i--)
		iprint(1, tab + i, 1);
}
