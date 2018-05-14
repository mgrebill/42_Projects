/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:21:38 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/20 12:29:26 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stackalloc(size_t size)
{
	t_stack	*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(new->stack = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	new->size = 0;
	return (new);
}
