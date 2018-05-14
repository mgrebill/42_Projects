/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:58:03 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 15:58:05 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str(t_id *id, va_list *ap)
{
	if (id->modifiers.l)
		return (ft_wstrtostr(va_arg(*ap, wchar_t *)));
	return (ft_strdup(va_arg(*ap, char *)));
}
