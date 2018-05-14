/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_ptr_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 14:55:34 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:03:49 by mgrebill         ###   ########.fr       */
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

char		*ft_flags_ptr_conv(t_id *id, char *str)
{
	ft_override_flags(id);
	if (id->dot && str[0] == '0')
		str[0] = '\0';
	if (id->dot)
		str = ft_precision_ptr_conv(*id, str);
	if (!id->dot)
		str = ft_strjoin_del_two("0x", str);
	if (id->mfw)
		str = ft_mfw_ptr_conv(*id, str);
	return (str);
}
