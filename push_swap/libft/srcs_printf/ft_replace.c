/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:08:43 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/21 14:32:37 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_ft	g_functions[19] = {
	{&ft_int, &ft_flags_sint_conv, 'i', PAD7},
	{&ft_int, &ft_flags_sint_conv, 'd', PAD7},
	{&ft_lint, &ft_flags_sint_conv, 'D', PAD7},
	{&ft_bin, &ft_flags_uint_conv, 'b', PAD7},
	{&ft_bin, &ft_flags_uint_conv, 'B', PAD7},
	{&ft_octal, &ft_flags_uint_conv, 'o', PAD7},
	{&ft_loctal, &ft_flags_uint_conv, 'O', PAD7},
	{&ft_udecimal, &ft_flags_uint_conv, 'u', PAD7},
	{&ft_ludecimal, &ft_flags_uint_conv, 'U', PAD7},
	{&ft_hexa, &ft_flags_uint_conv, 'x', PAD7},
	{&ft_hexxa, &ft_flags_uint_conv, 'X', PAD7},
	{&ft_char, &ft_flags_char_conv, 'c', PAD7},
	{&ft_wchar, &ft_flags_char_conv, 'C', PAD7},
	{&ft_str, &ft_flags_char_conv, 's', PAD7},
	{&ft_wstr, &ft_flags_char_conv, 'S', PAD7},
	{&ft_pointer, &ft_flags_ptr_conv, 'p', PAD7},
	{&ft_percent, &ft_flags_char_conv, '%', PAD7},
	{&ft_kolor, &ft_flags_kolor_conv, 'k', PAD7},
	{NULL, NULL, 0, PAD7}
};

void	ft_replace(t_lst_pf *tmp, va_list *ap)
{
	int		i;
	t_id	id;

	i = 0;
	tmp->size = 0;
	id = ft_split_identifier(tmp->str);
	while (g_functions[i].c && id.type != g_functions[i].c)
		i++;
	free(tmp->str);
	if (g_functions[i].c)
	{
		tmp->str = g_functions[i].ft(&id, ap);
		if ((id.type == 'c' || id.type == 'C') && !tmp->str[0])
			tmp->size++;
		tmp->str = g_functions[i].flags(&id, tmp->str);
	}
	else
	{
		tmp->str = ft_chartostr(id.type);
		id.type = 'c';
		tmp->str = ft_flags_char_conv(&id, tmp->str);
	}
	tmp->size += ft_strlen(tmp->str);
}
