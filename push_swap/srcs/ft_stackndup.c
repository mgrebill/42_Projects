/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:13:17 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/21 12:41:17 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stackndup(t_stack *origin, size_t size)
{
	size_t	i;
	t_stack	*new;

	if (!(new = ft_stackalloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new->stack[i] = origin->stack[i];
		i++;
	}
	new->size = size;
	return (new);
}
