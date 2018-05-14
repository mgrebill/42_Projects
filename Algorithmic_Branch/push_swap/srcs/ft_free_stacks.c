/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:40:52 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/16 14:56:41 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		if (stack_a->stack)
			free(stack_a->stack);
		free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->stack)
			free(stack_b);
		free(stack_b->stack);
	}
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}
