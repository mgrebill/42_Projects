/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_uint_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:54:54 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:01:01 by mgrebill         ###   ########.fr       */
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

char		*ft_flags_uint_conv(t_id *id, char *str)
{
	ft_override_flags(id);
	if (str[0] == '0')
	{
		if (id->type != 'o' && id->type != 'O')
			id->flags.sharp = false;
		if (id->dot || ((id->type == 'o' || id->type == 'O') &&
															id->flags.sharp))
			str[0] = '\0';
	}
	if ((id->type == 'o' || id->type == 'O') && id->precision > ft_strlen(str))
		id->flags.sharp = false;
	if (id->dot)
		str = ft_precision_uint_conv(*id, str);
	if (id->flags.sharp && id->type != 'u' && id->type != 'U')
		str = ft_strjoin_del_two(ft_sharp(*id), str);
	if (id->mfw)
		str = ft_mfw_uint_conv(*id, str);
	return (str);
}
