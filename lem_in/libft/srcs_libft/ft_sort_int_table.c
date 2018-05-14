/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:42:55 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 16:29:50 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_int_table(int *tab)
{
	int i;
	int sorted;

	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (tab[i] && tab[i + 1])
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap_int(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}
