/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:18:51 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/04 17:00:54 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_final(t_lst_pf *lst)
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

int			ft_printf(const char *format, ...)
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
