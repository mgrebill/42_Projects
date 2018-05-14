/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:32:21 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 20:32:25 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab_tab(char ***double_tab)
{
	int i;

	i = 0;
	if (double_tab)
	{
		while (double_tab[0][i])
		{
			free(double_tab[0][i]);
			i++;
		}
		free(double_tab[0]);
	}
	return ;
}
