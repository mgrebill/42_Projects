/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfw_uint_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:51:02 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:37:06 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mfw_uint_conv(t_id id, char *str)
{
	size_t	len;
	size_t	i;
	char	*fill;

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
	if (id.flags.sharp && id.flags.zero && id.type != 'u' && id.type != 'U' &&
																(str[1] = '0'))
		fill[1] = id.type;
	return (ft_strjoin_del_both(fill, str));
}
