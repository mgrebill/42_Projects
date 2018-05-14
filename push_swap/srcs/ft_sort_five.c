/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:12:02 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/11 12:33:47 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_manage_ptr(t_lst_cmd **start, t_lst_cmd **cmd,
																const char *str)
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

static t_lst_cmd	*ft_statico_push_mediane_b(t_stack *stack_a,
		t_stack *stack_b)
{
	int			i;
	int			mediane;
	t_lst_cmd	*start;
	t_lst_cmd	*cmd;

	mediane = ft_find_mediane(stack_a, 5);
	start = NULL;
	cmd = NULL;
	i = 0;
	while (i != 2)
		if (stack_a->stack[0] < mediane)
		{
			ft_p(stack_a, stack_b, 'b');
			ft_manage_ptr(&start, &cmd, "pb");
			i++;
		}
		else
		{
			ft_r(stack_a, stack_b, 'a');
			ft_manage_ptr(&start, &cmd, "ra");
		}
	return (start);
}

t_lst_cmd			*ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_lst_cmd	*start;
	t_lst_cmd	*cmd;

	cmd = ft_statico_push_mediane_b(stack_a, stack_b);
	start = cmd;
	while (cmd->next)
		cmd = cmd->next;
	cmd->next = ft_little_swap_b(stack_a, stack_b);
	while (cmd->next)
		cmd = cmd->next;
	cmd->next = ft_sort_three(stack_a, stack_b);
	while (cmd->next)
		cmd = cmd->next;
	cmd->next = ft_new_cmd("pa");
	cmd = cmd->next;
	cmd->next = ft_new_cmd("pa");
	return (start);
}
