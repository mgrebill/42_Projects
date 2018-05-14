/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_kolor_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:35:19 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/06 16:55:17 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags_kolor_conv(t_id *id, char *str)
{
	if (id->flags.zero)
		return (ft_strdup("\33[0m"));
	str = ft_strjoin_del_two("\033[", str);
	if (id->mfw)
	{
		str = ft_strjoin_del_one(str, ";");
		str = ft_strjoin_del_both(str, ft_uitoa(id->mfw));
	}
	if (id->flags.minus)
		str = ft_strjoin_del_one(str, ";4");
	if (id->flags.plus)
		str = ft_strjoin_del_one(str, ";1");
	if (id->flags.sharp)
		str = ft_strjoin_del_one(str, ";7");
	return (ft_strjoin_del_one(str, "m"));
}
