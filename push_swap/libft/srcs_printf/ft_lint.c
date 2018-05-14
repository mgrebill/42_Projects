/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:01:43 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:01:55 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lint(t_id *id, va_list *ap)
{
	if (id->modifiers.j)
		return (ft_itoa(va_arg(*ap, intmax_t)));
	if (id->modifiers.z)
		return (ft_itoa(va_arg(*ap, ssize_t)));
	if (id->modifiers.ll)
		return (ft_itoa(va_arg(*ap, long long int)));
	return (ft_itoa(va_arg(*ap, long int)));
}
