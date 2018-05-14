/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ludecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:00:19 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:00:20 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ludecimal(t_id *id, va_list *ap)
{
	if (id->modifiers.j)
		return (ft_uitoa(va_arg(*ap, uintmax_t)));
	if (id->modifiers.z)
		return (ft_uitoa(va_arg(*ap, size_t)));
	if (id->modifiers.ll)
		return (ft_uitoa(va_arg(*ap, unsigned long long int)));
	return (ft_uitoa(va_arg(*ap, unsigned long int)));
}
