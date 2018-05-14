/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfw_ptr_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:18:51 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:38:22 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mfw_ptr_conv(t_id id, char *str)
{
	char	*fill;
	size_t	len;
	size_t	i;

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
	if (id.flags.zero && (str[1] = '0'))
		fill[1] = 'x';
	return (ft_strjoin_del_both(fill, str));
}
