/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfw_sint_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:00:15 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:36:43 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mfw_sint_conv(t_id id, char *str)
{
	char	*fill;
	bool	neg;
	size_t	len;
	size_t	i;

	neg = (str[0] == '-' ? true : false);
	len = ft_strlen(str);
	if (id.mfw <= len)
		return (str);
	if (!(fill = ft_strnew(id.mfw - len)))
		return (NULL);
	i = 0;
	while (i != id.mfw - len)
		fill[i++] = id.flags.zero ? '0' : ' ';
	if (id.flags.minus)
		return (ft_strjoin_del_both(str, fill));
	if (id.flags.plus && id.flags.zero && (str[0] = '0'))
		fill[0] = '+';
	if (neg && id.flags.zero && (str[0] = '0'))
		fill[0] = '-';
	if (id.flags.blank && id.flags.zero && (str[0] = '0'))
		fill[0] = ' ';
	return (ft_strjoin_del_both(fill, str));
}
