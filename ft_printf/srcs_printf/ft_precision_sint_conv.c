/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_sint_conv.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:44:57 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/05 18:23:01 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_tmp(t_id *tmp)
{
	tmp->flags.minus = false;
	tmp->flags.zero = false;
	tmp->flags.plus = false;
	tmp->flags.blank = false;
	tmp->flags.sharp = false;
	tmp->flags.quote = false;
	tmp->modifiers.hh = false;
	tmp->modifiers.h = false;
	tmp->modifiers.l = false;
	tmp->modifiers.ll = false;
	tmp->modifiers.z = false;
	tmp->modifiers.j = false;
	tmp->dot = false;
	tmp->mfw = 0;
	tmp->precision = 0;
	tmp->type = '\0';
}

char		*ft_precision_sint_conv(t_id id, char *str)
{
	t_id	tmp;
	char	*result;

	ft_init_tmp(&tmp);
	tmp.flags.zero = true;
	tmp.mfw = id.precision;
	if (str[0] == '-')
	{
		result = ft_strjoin_del_two("-", ft_mfw_sint_conv(tmp, ft_strsub(str, 1,
														ft_strlen(str) - 1)));
		free(str);
		return (result);
	}
	return (ft_mfw_sint_conv(tmp, str));
}
