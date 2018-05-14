/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:26:10 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/10 17:08:01 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_cmd	*ft_sort_three(t_stack *stack_a, t_stack *stack_b)
{
	t_lst_cmd	*cmd;

	cmd = NULL;
	if (stack_a->stack[0] > stack_a->stack[1] &&
		stack_a->stack[0] > stack_a->stack[2])
	{
		ft_r(stack_a, stack_b, 'a');
		cmd = ft_new_cmd("ra");
		cmd->next = ft_little_swap_a(stack_a, stack_b);
		return (cmd);
	}
	else if (stack_a->stack[1] > stack_a->stack[0] &&
			stack_a->stack[1] > stack_a->stack[2])
	{
		ft_rr(stack_a, stack_b, 'a');
		cmd = ft_new_cmd("rra");
		cmd->next = ft_little_swap_a(stack_a, stack_b);
		return (cmd);
	}
	else
		return (ft_little_swap_a(stack_a, stack_b));
}
