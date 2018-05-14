/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:36:19 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/07 13:04:32 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int result;
	int negative;

	i = 0;
	result = 0;
	negative = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative = -1;
	while (str[i] > 47 && str[i] < 58)
	{
		result = result + (str[i] - 48);
		if (str[i + 1] > 47 && str[i + 1] < 58)
			result = result * 10;
		i++;
	}
	return (result * negative);
}
