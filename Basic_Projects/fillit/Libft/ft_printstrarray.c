/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:39:50 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/14 10:42:32 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrarray(char **array, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
