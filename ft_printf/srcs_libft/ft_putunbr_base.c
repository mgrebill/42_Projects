/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:13:18 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/25 19:16:43 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_base(uintmax_t n, int base)
{
	if (n / base)
		ft_putunbr_base(n / base, base);
	ft_putchar((n % base) + (n % base > 9 ? 55 : 48));
}
