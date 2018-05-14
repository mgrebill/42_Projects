/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:12:36 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/06 14:49:00 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(t_id id)
{
	if (id.type == 'o' || id.type == 'O')
		return ("0");
	if (id.type == 'x')
		return ("0x");
	if (id.type == 'X')
		return ("0X");
	if (id.type == 'b')
		return ("0b");
	if (id.type == 'B')
		return ("0B");
	if (id.type == 'p')
		return ("0x");
	return (NULL);
}
