/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexxa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:02:46 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:34:00 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexxa(t_id *id, va_list *ap)
{
	if (id->modifiers.j)
		return (ft_uitoa_base(va_arg(*ap, uintmax_t), 16));
	if (id->modifiers.z)
		return (ft_uitoa_base(va_arg(*ap, size_t), 16));
	if (id->modifiers.ll)
		return (ft_uitoa_base(va_arg(*ap, unsigned long long int), 16));
	if (id->modifiers.l)
		return (ft_uitoa_base(va_arg(*ap, unsigned long int), 16));
	if (id->modifiers.h)
	{
		return (ft_uitoa_base((unsigned short int)va_arg(*ap, unsigned int),
																		16));
	}
	if (id->modifiers.hh)
		return (ft_uitoa_base((unsigned char)va_arg(*ap, unsigned int), 16));
	return (ft_uitoa_base(va_arg(*ap, unsigned int), 16));
}
