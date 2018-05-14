/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:04:26 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/06 16:12:31 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_override_flags(t_id *id)
{
	if (id->flags.minus)
		id->flags.zero = false;
	if (id->flags.plus)
		id->flags.blank = false;
}

char		*ft_flags_char_conv(t_id *id, char *str)
{
	ft_override_flags(id);
	if (!str)
		str = ft_strdup("(null)");
	if (id->dot)
		str = ft_precision_char_conv(*id, str);
	if (id->mfw)
		str = ft_mfw_char_conv(*id, str);
	return (str);
}
