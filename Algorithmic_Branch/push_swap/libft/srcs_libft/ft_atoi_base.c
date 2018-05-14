/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:29:58 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/25 14:32:52 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi_base(const char *str, int base)
{
	int			i;
	int			negative;
	intmax_t	result;

	i = 0;
	result = 0;
	negative = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative = -1;
	i--;
	while ((str[i + 1] > 47 && str[i + 1] < 58)
			|| (str[i + 1] > 64 && str[i + 1] < 91))
	{
		if (str[i + 1] > 47 && str[i + 1] < 58)
			result = result * base + (str[i + 1] - 48);
		else
			result = result * base + (str[i + 1] - 55);
		i++;
	}
	return (result * negative);
}
