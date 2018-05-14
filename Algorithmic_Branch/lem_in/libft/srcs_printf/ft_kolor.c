/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:28:14 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/20 12:11:49 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_kolor(t_id *id, va_list *ap)
{
	if (id->flags.zero)
		return (ft_uitoa(0));
	return (ft_uitoa(va_arg(*ap, int)));
}
