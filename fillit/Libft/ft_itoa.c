/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:27:26 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/19 17:41:30 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_minint(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char		*ft_special_case(int n)
{
	char	*str;

	if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	else if (n == (-2147483648))
		return (ft_minint());
	return (0);
}

static char		*ft_reduce(int n, int i, char *str, int is_neg)
{
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		i++;
		n /= 10;
	}
	if (is_neg)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		is_neg;
	int		i;
	int		nb;
	char	*str;

	i = 0;
	if (n == 0 || n == (-2147483648))
		return (ft_special_case(n));
	if ((is_neg = (n < 0)))
		n = -n;
	nb = n;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1 + is_neg)))
		return (NULL);
	return (ft_strreverse(ft_reduce(n, 0, str, is_neg)));
}
