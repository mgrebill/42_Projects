/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:16:46 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/15 17:26:48 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size_base(long int nb, int base)
{
	long int	d;
	size_t		size;

	d = 1;
	size = 0;
	if (nb < 0)
	{
		size++;
		nb = nb * -1;
	}
	while (nb > d)
	{
		d = d * base;
		size++;
	}
	if (!size)
		size++;
	return (size);
}

char			*ft_itoa_base(int n, int base)
{
	long int	nb;
	int			negative;
	char		*a;
	size_t		size;

	nb = n;
	size = ft_find_size_base(nb, base);
	if (base > 36 || base < 2 || !(a = ft_strnew(size)))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
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
