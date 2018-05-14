/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:29:56 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/11 12:32:52 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_cmd			*ft_quick_sort_a(t_stack *stack_a, t_stack *stack_b,
																	size_t size)
{
	t_lst_cmd	*start;
	t_lst_cmd	*cmd;

	start = NULL;
	cmd = NULL;
	if (size > 2)
	{
		cmd = ft_push_mediane_b(stack_a, stack_b, size);
		start = cmd;
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_quick_sort_a(stack_a, stack_b, size - (size / 2));
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_quick_sort_b(stack_a, stack_b, size / 2);
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_push_half_a(stack_a, stack_b, size);
	}
	else if (size == 2)
		start = ft_little_swap_a(stack_a, stack_b);
	return (start);
}

t_lst_cmd			*ft_quick_sort_b(t_stack *stack_a, t_stack *stack_b,
																	size_t size)
{
	t_lst_cmd	*start;
	t_lst_cmd	*cmd;

	start = NULL;
	cmd = NULL;
	if (size > 2)
	{
		cmd = ft_push_mediane_a(stack_a, stack_b, size);
		start = cmd;
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_quick_sort_b(stack_a, stack_b, size - (size / 2));
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_quick_sort_a(stack_a, stack_b, size / 2);
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = ft_push_half_b(stack_a, stack_b, size);
	}
	else if (size == 2)
		start = ft_little_swap_b(stack_a, stack_b);
	return (start);
}
