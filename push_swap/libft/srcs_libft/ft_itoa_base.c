/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:16:46 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/25 14:59:31 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size_base(intmax_t nb, int base)
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
		d = d * base;
		size++;
	}
	if (!size)
		size++;
	return (size);
}

char			*ft_itoa_base(intmax_t n, int base)
{
	bool		negative;
	char		*a;
	size_t		size;
	uintmax_t	nb;

	size = ft_find_size_base(n, base);
	if (base > 36 || base < 2 || !(a = ft_strnew(size)))
		return (NULL);
	nb = n;
	if (!(negative = false) && n < 0)
	{
		nb = n * -1;
		negative = 1;
	}
	if (!(a[0] = '0') || nb == 0)
		return (a);
	size--;
	while (nb)
	{
		a[size--] = (nb % base < 10) ? nb % base + 48 : nb % base + 55;
		nb = nb / base;
	}
	if (negative)
		a[size] = '-';
	return (a);
}
