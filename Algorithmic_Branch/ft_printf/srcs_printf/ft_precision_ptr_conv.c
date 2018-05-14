/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_ptr_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:04:37 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/06 16:07:56 by mgrebill         ###   ########.fr       */
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

char		*ft_precision_ptr_conv(t_id id, char *str)
{
	t_id	tmp;

	ft_init_tmp(&tmp);
	tmp.flags.zero = true;
	tmp.mfw = id.precision;
	return (ft_strjoin_del_two("0x", ft_mfw_uint_conv(tmp, str)));
}
