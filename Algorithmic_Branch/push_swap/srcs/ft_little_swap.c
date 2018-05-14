/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:07:52 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/10 15:08:33 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_cmd	*ft_little_swap_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack[0] > stack_a->stack[1])
	{
		ft_s(stack_a, stack_b, 'a');
		return (ft_new_cmd("sa"));
	}
	return (NULL);
}

t_lst_cmd	*ft_little_swap_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->stack[0] < stack_b->stack[1])
	{
		ft_s(stack_a, stack_b, 'b');
		return (ft_new_cmd("sb"));
	}
	return (NULL);
}
