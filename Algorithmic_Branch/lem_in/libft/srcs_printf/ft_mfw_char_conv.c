/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfw_char_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:03:14 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:37:35 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mfw_char_conv(t_id id, char *str)
{
	char	*fill;
	size_t	len;
	size_t	i;

	if ((id.type == 'c' || id.type == 'C') && !str[0])
		id.mfw--;
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
	return (ft_strjoin_del_both(fill, str));
}
