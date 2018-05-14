/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:03:58 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:03:59 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(t_id *id, va_list *ap)
{
	if (id->modifiers.l)
		return (ft_wchartostr(va_arg(*ap, wchar_t)));
	return (ft_chartostr((char)va_arg(*ap, int)));
}
