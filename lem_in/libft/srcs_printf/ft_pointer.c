/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:58:13 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:45:00 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pointer(t_id *id, va_list *ap)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_uitoa_base(va_arg(*ap, intmax_t), 16);
	while (str[i])
	{
		str[i] = ft_isalpha(str[i]) ? ft_tolower(str[i]) : str[i];
		i++;
	}
	return (str);
	if (id)
		return (NULL);
}
