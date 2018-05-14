/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:38:29 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/20 11:51:12 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubblesort_chararray(char **tab, size_t n)
{
	int		sorted;
	size_t	i;
	char	*str;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				str = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = str;
				sorted = 0;
			}
			i++;
		}
	}
}
