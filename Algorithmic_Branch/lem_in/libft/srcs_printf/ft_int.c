/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:02:13 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:02:14 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_int(t_id *id, va_list *ap)
{
	if (id->modifiers.j)
		return (ft_itoa(va_arg(*ap, intmax_t)));
	if (id->modifiers.z)
		return (ft_itoa(va_arg(*ap, ssize_t)));
	if (id->modifiers.ll)
		return (ft_itoa(va_arg(*ap, long long int)));
	if (id->modifiers.l)
		return (ft_itoa(va_arg(*ap, long int)));
	if (id->modifiers.h)
		return (ft_itoa((short int)va_arg(*ap, int)));
	if (id->modifiers.hh)
		return (ft_itoa((char)va_arg(*ap, int)));
	return (ft_itoa(va_arg(*ap, int)));
}
