/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sint_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:17:14 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/06 14:01:57 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_override_flags(t_id *id)
{
	if (id->dot)
		id->flags.zero = false;
	if (id->flags.minus)
		id->flags.zero = false;
	if (id->flags.plus)
		id->flags.blank = false;
}

char		*ft_flags_sint_conv(t_id *id, char *str)
{
	ft_override_flags(id);
	if (str[0] == '0' && id->dot)
		str[0] = '\0';
	if (id->dot)
		str = ft_precision_sint_conv(*id, str);
	if (id->flags.blank && str[0] != '-')
		str = ft_strjoin_del_two(" ", str);
	if (id->flags.plus && str[0] != '-')
		str = ft_strjoin_del_two("+", str);
	if (id->mfw)
		str = ft_mfw_sint_conv(*id, str);
	return (str);
}
