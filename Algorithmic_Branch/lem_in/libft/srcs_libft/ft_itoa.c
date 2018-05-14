/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:23:28 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 15:24:13 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size(intmax_t nb)
{
	uintmax_t	d;
	uintmax_t	unb;
	size_t		size;

	d = 1;
	size = 0;
	unb = nb;
	if (nb < 0)
	{
		size++;
		unb = nb * -1;
	}
	while (unb >= d)
	{
		d = d * 10;
		size++;
	}
	if (!size)
		size++;
	return (size);
}

char			*ft_itoa(intmax_t n)
{
	int			negative;
	char		*a;
	size_t		size;
	uintmax_t	nb;

	size = ft_find_size(n);
	if (!(a = ft_strnew(size)))
		return (NULL);
	nb = n;
	if (n < 0)
	{
		nb = n * -1;
		negative = 1;
	}
	if (!(a[0] = '0') || nb == 0)
		return (a);
	size--;
	while (nb)
	{
		a[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (negative)
		a[size] = '-';
	return (a);
}
