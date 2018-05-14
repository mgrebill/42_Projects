/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:51:31 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/04 12:45:54 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size_base(uintmax_t nb, int base)
{
	uintmax_t	d;
	size_t		size;

	d = 1;
	size = 0;
	while (nb >= d)
	{
		d = d * base;
		size++;
		if (d == 0)
			break ;
	}
	if (!size)
		size++;
	return (size);
}

char			*ft_uitoa_base(uintmax_t n, int base)
{
	char				*a;
	size_t				size;

	size = ft_find_size_base(n, base);
	if (base > 36 || base < 2 || !(a = ft_strnew(size)))
		return (NULL);
	if (!(a[0] = '0') || n == 0)
		return (a);
	size--;
	while (n)
	{
		a[size--] = (n % base < 10) ? n % base + 48 : n % base + 55;
		n = n / base;
	}
	return (a);
}
