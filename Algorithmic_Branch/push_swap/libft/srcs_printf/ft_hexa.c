/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:03:12 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:03:13 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa(t_id *id, va_list *ap)
{
	char	*str;
	int		i;

	if (id->modifiers.j)
		str = ft_uitoa_base(va_arg(*ap, uintmax_t), 16);
	else if (id->modifiers.z)
		str = ft_uitoa_base(va_arg(*ap, size_t), 16);
	else if (id->modifiers.ll)
		str = ft_uitoa_base(va_arg(*ap, unsigned long long int), 16);
	else if (id->modifiers.l)
		str = ft_uitoa_base(va_arg(*ap, unsigned long int), 16);
	else if (id->modifiers.h)
		str = ft_uitoa_base((unsigned short int)va_arg(*ap, unsigned int), 16);
	else if (id->modifiers.hh)
		str = ft_uitoa_base((unsigned char)va_arg(*ap, unsigned int), 16);
	else
		str = ft_uitoa_base(va_arg(*ap, unsigned int), 16);
	i = 0;
	while (str[i])
	{
		str[i] = ft_isalpha(str[i]) ? ft_tolower(str[i]) : str[i];
		i++;
	}
	return (str);
}
