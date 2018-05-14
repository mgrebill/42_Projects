/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 18:47:43 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/04 16:47:30 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size(uintmax_t nb)
{
	uintmax_t	d;
	size_t		size;

	d = 1;
	size = 0;
	if (nb > 9999999999999999999U)
		return (20);
	while (nb >= d)
	{
		d = d * 10;
		size++;
	}
	if (!size)
		size++;
	return (size);
}

char			*ft_uitoa(uintmax_t n)
{
	char	*a;
	size_t	size;

	size = ft_find_size(n);
	if (!(a = ft_strnew(size)))
		return (NULL);
	if (!(a[0] = '0') || n == 0)
		return (a);
	size--;
	while (n)
	{
		a[size--] = (n % 10) + 48;
		n = n / 10;
	}
	return (a);
}
