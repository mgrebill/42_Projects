/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 10:49:00 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/15 16:38:34 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack *stack_a, t_stack *stack_b, char stack)
{
	t_stack	*target;

	if (stack == 'a')
		target = stack_a;
	else if (stack == 'b')
		target = stack_b;
	else
	{
		target = stack_a;
		ft_s(stack_a, stack_b, 'b');
	}
	ft_swap_int(&target->stack[0], &target->stack[1]);
}

void	ft_r(t_stack *stack_a, t_stack *stack_b, char stack)
{
	t_stack	*target;
	int		tmp;
	size_t	i;

	if (stack == 'a')
		target = stack_a;
	else if (stack == 'b')
		target = stack_b;
	else
	{
		target = stack_a;
		ft_r(stack_a, stack_b, 'b');
	}
	tmp = target->stack[0];
	i = 1;
	while (i < target->size)
	{
		target->stack[i - 1] = target->stack[i];
		i++;
	}
	target->stack[i - 1] = tmp;
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, char stack)
{
	t_stack	*target;
	int		tmp;
	size_t	i;

	if (stack == 'a')
		target = stack_a;
	else if (stack == 'b')
		target = stack_b;
	else
	{
		target = stack_a;
		ft_rr(stack_a, stack_b, 'b');
	}
	tmp = target->stack[target->size - 1];
	i = target->size - 1;
	while (i)
	{
		target->stack[i] = target->stack[i - 1];
		i--;
	}
	target->stack[0] = tmp;
}

void	ft_p(t_stack *stack_a, t_stack *stack_b, char stack)
{
	t_stack	*target1;
	t_stack	*target2;

	if (stack == 'a' && stack_b->size)
	{
		target1 = stack_a;
		target2 = stack_b;
	}
	else if (stack == 'b' && stack_a->size)
	{
		target1 = stack_b;
		target2 = stack_a;
	}
	else
		return ;
	target1->size++;
	ft_rr(target2, target1, 'b');
	target1->stack[0] = target2->stack[0];
	ft_r(target2, target1, 'a');
	target2->size--;
}
