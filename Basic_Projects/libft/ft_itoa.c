/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:23:28 by mgrebill          #+#    #+#             */
/*   Updated: 2017/02/01 16:11:58 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size(long int nb)
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
	while (nb >= d)
	{
		d = d * 10;
		size++;
	}
	if (!size)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	int			negative;
	char		*a;
	size_t		size;
	long int	nb;

	nb = n;
	size = ft_find_size(nb);
	if (!(a = ft_strnew(size)))
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
		a[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (negative)
		a[size] = '-';
	return (a);
}
