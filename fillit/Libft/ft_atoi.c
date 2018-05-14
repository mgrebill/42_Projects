/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:27:48 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/03 16:29:24 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		nb;
	int		str_start;
	int		str_len;

	nb = 0;
	str_len = 0;
	while (str[str_len] == ' ' || str[str_len] == '\t' || str[str_len] == '\v'
			|| str[str_len] == '\f' || str[str_len] == '\r' ||
			str[str_len] == '\n')
		str_len++;
	str_start = str_len;
	if (str[str_len] == '-' || str[str_len] == '+')
		str_len++;
	while (str[str_len] >= '0' && str[str_len] <= '9')
	{
		nb = nb * 10 + (str[str_len] - '0');
		str_len++;
	}
	if (str[str_start] == '-')
		nb *= -1;
	return (nb);
}
