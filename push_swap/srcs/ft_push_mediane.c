/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_mediane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:00:46 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/04 15:21:20 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_manage_ptr(t_lst_cmd **start, t_lst_cmd **cmd, const char *str)
{
	if (!(*cmd))
	{
		*cmd = ft_new_cmd(str);
		*start = *cmd;
	}
	else
	{
		(*cmd)->next = ft_new_cmd(str);
		*cmd = (*cmd)->next;
	}
}

static void	ft_init_var(t_push_mediane_var *var, t_stack *stack, size_t size)
{
	var->start = NULL;
	var->cmd = NULL;
	var->i = 0;
	var->r = 0;
	var->mediane = ft_find_mediane(stack, size);
}

t_lst_cmd	*ft_push_mediane_a(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_push_mediane_var	var;

	ft_init_var(&var, stack_b, size);
	while (var.i != size / 2)
		if (stack_b->stack[0] > var.mediane)
		{
			ft_p(stack_a, stack_b, 'a');
			ft_manage_ptr(&var.start, &var.cmd, "pa");
			var.i++;
		}
		else
		{
			ft_r(stack_a, stack_b, 'b');
			ft_manage_ptr(&var.start, &var.cmd, "rb");
			var.r++;
		}
	while (var.r--)
	{
		ft_rr(stack_a, stack_b, 'b');
		ft_manage_ptr(&var.start, &var.cmd, "rrb");
	}
	return (var.start);
}

t_lst_cmd	*ft_push_mediane_b(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_push_mediane_var	var;

	ft_init_var(&var, stack_a, size);
	while (var.i != size / 2)
		if (stack_a->stack[0] < var.mediane ||
				(!(size % 2) && stack_a->stack[0] == var.mediane))
		{
			ft_p(stack_a, stack_b, 'b');
			ft_manage_ptr(&var.start, &var.cmd, "pb");
			var.i++;
		}
		else
		{
			ft_r(stack_a, stack_b, 'a');
			ft_manage_ptr(&var.start, &var.cmd, "ra");
			var.r++;
		}
	while (var.r--)
	{
		ft_rr(stack_a, stack_b, 'a');
		ft_manage_ptr(&var.start, &var.cmd, "rra");
	}
	return (var.start);
}
