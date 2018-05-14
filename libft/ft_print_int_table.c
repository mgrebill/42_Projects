/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:50:24 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 16:30:48 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_table(int *tab)
{
	if (tab)
		while (*tab)
		{
			ft_putnbr(*tab++);
			ft_putchar('\n');
		}
}
