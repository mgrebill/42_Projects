/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:50:24 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/24 16:51:30 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_table(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	if (tab)
		while (i < size)
		{
			ft_putnbr(tab[i++]);
			ft_putchar('\n');
		}
}
