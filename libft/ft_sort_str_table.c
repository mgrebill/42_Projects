/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:33:12 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 17:51:36 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_str_table(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_str(tab[i], tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}
