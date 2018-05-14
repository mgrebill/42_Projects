/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:49:32 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/25 20:02:03 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(intmax_t n, int base)
{
	uintmax_t nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb / base)
		ft_putnbr_base(nb / base, base);
	ft_putchar((nb % base) + (nb % base > 9 ? 55 : 48));
}
