/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:15:24 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/14 11:20:38 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_error(int n)
{
	long int nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_error('-');
	}
	if (nb / 10)
		ft_putnbr_error(nb / 10);
	ft_putchar_error((nb % 10) + 48);
}
