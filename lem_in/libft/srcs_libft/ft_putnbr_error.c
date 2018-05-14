/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:15:24 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/25 19:11:31 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_error(intmax_t n)
{
	uintmax_t nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar_error('-');
	}
	else
		nb = n;
	if (nb / 10)
		ft_putnbr_error(nb / 10);
	ft_putchar_error((nb % 10) + 48);
}
