/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loctal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:02:05 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:02:06 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_loctal(t_id *id, va_list *ap)
{
	if (id->modifiers.j)
		return (ft_uitoa_base(va_arg(*ap, uintmax_t), 8));
	if (id->modifiers.z)
		return (ft_uitoa_base(va_arg(*ap, size_t), 8));
	if (id->modifiers.ll)
		return (ft_uitoa_base(va_arg(*ap, unsigned long long int), 8));
	return (ft_uitoa_base(va_arg(*ap, unsigned long int), 8));
}
