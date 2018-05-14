/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:42:55 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/24 17:30:57 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_int_table(int *tab, size_t size)
{
	size_t	i;
	bool	sorted;

	sorted = false;
	while (!sorted)
	{
		i = 0;
		sorted = true;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap_int(&tab[i], &tab[i + 1]);
				sorted = false;
			}
			i++;
		}
	}
}
