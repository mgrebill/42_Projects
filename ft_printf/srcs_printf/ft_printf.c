/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:18:51 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:43:14 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_ft	g_functions[19] = {
	{'i', &ft_int, &ft_flags_sint_conv},
	{'d', &ft_int, &ft_flags_sint_conv},
	{'D', &ft_lint, &ft_flags_sint_conv},
	{'b', &ft_bin, &ft_flags_uint_conv},
	{'B', &ft_bin, &ft_flags_uint_conv},
	{'o', &ft_octal, &ft_flags_uint_conv},
	{'O', &ft_loctal, &ft_flags_uint_conv},
	{'u', &ft_udecimal, &ft_flags_uint_conv},
	{'U', &ft_ludecimal, &ft_flags_uint_conv},
	{'x', &ft_hexa, &ft_flags_uint_conv},
	{'X', &ft_hexxa, &ft_flags_uint_conv},
	{'c', &ft_char, &ft_flags_char_conv},
	{'C', &ft_wchar, &ft_flags_char_conv},
	{'s', &ft_str, &ft_flags_char_conv},
	{'S', &ft_wstr, &ft_flags_char_conv},
	{'p', &ft_pointer, &ft_flags_ptr_conv},
	{'%', &ft_percent, &ft_flags_char_conv},
	{'k', &ft_kolor, &ft_flags_kolor_conv},
	{0, NULL, NULL}
};

int		ft_print_final(t_lst_pf *lst)
{
	int			ret;
	t_lst_pf	*tmp;

	ret = 0;
	while (lst)
	{
		write(1, lst->str, lst->size);
		ret += lst->size;
		free(lst->str);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (ret);
}

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

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst_pf	*start_lst_ptr;
	t_lst_pf	*tmp;

	start_lst_ptr = ft_split_format(format);
	va_start(ap, format);
	tmp = start_lst_ptr;
	while (tmp)
	{
		if (tmp->str[0] == '%')
			ft_replace(tmp, &ap);
		else
			tmp->size = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	va_end(ap);
	return (ft_print_final(start_lst_ptr));
}
