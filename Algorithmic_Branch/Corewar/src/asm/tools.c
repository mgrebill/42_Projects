/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:25:43 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 17:25:44 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t								write_be(
	int fd,
	void *buff,
	size_t size)
{
	size_t							res;

	res = 0;
	while (size--)
		res += write(fd, (uint8_t *)buff + size, 1);
	return (res);
}

int									error_message_with_string(
	const char *const restrict msg,
	const char *const restrict str)
{
	int								size;

	size = 0;
	while (msg[size])
		++size;
	write(2, msg, size);
	size = 0;
	while (str[size])
		++size;
	write(2, str, size);
	write(2, "\n", 1);
	return (1);
}

int									error_message_with_number(
	const char *const restrict msg,
	int nbr)
{
	char							reverse_buffer[23];
	int								i;
	int								size;

	size = 0;
	while (msg[size])
		++size;
	write(2, msg, size);
	i = 0;
	reverse_buffer[i++] = nbr % 10 + '0';
	while ((nbr /= 10))
		reverse_buffer[i++] = nbr % 10 + '0';
	while (i)
		write(2, reverse_buffer + --i, 1);
	return (1);
}

int									error_message_with_char(
	const char *const restrict msg,
	const char c)
{
	int								size;

	size = 0;
	while (msg[size])
		++size;
	write(2, msg, size);
	write(2, &c, 1);
	write(2, " at ", 4);
	error_message_with_number("", (int)g_line_i);
	write(2, ":", 1);
	error_message_with_number("", (int)g_char_i);
	write(2, "\n", 1);
	return (1);
}
