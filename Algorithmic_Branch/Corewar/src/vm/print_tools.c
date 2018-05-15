/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 08:06:49 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/03 08:06:50 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void								set_cursor_new_line(
	const uint16_t x)
{
	write(1, "\033[1e", 4);
	write(1, "\033[", 2);
	print_nbr_base(x, 10);
	write(1, "G", 1);
}

void								set_cursor(
	const uint16_t x,
	const uint16_t y)
{
	write(1, "\033[", 2);
	print_nbr_base(y, 10);
	write(1, ";", 1);
	print_nbr_base(x, 10);
	write(1, "H", 1);
}

int									print_left(
	const char *const restrict text,
	const uint16_t x,
	const uint16_t y)
{
	int								size;

	size = 0;
	while (text[size])
		++size;
	set_cursor(x, y);
	write(1, text, size);
	return (size);
}

void								print_nbr_base(
	uint64_t nbr,
	uint8_t base)
{
	char							tab[23];
	int								i;

	i = 0;
	tab[i++] = nbr % base + (nbr % base > 9 ? 87 : 48);
	while ((nbr /= base))
		tab[i++] = nbr % base + (nbr % base > 9 ? 87 : 48);
	while (i--)
		write(1, tab + i, 1);
}
