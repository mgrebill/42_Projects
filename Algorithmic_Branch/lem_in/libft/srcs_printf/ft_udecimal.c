/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:57:53 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 15:57:55 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_udecimal(t_id *id, va_list *ap)
{
	if (id->modifiers.j)
		return (ft_uitoa(va_arg(*ap, uintmax_t)));
	if (id->modifiers.z)
		return (ft_uitoa(va_arg(*ap, size_t)));
	if (id->modifiers.ll)
		return (ft_uitoa(va_arg(*ap, unsigned long long int)));
	if (id->modifiers.l)
		return (ft_uitoa(va_arg(*ap, unsigned long int)));
	if (id->modifiers.h)
		return (ft_uitoa((unsigned short int)va_arg(*ap, unsigned int)));
	if (id->modifiers.hh)
		return (ft_uitoa((unsigned char)va_arg(*ap, unsigned int)));
	return (ft_uitoa(va_arg(*ap, unsigned int)));
}
