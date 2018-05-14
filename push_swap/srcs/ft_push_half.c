/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_half.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:01:20 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/03 15:42:47 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_cmd	*ft_push_half_a(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_lst_cmd	*start;
	t_lst_cmd	*cmd;
	size_t		i;

	start = NULL;
	cmd = NULL;
	i = 0;
	while (i != size / 2)
	{
		ft_p(stack_a, stack_b, 'a');
		if (!cmd)
		{
			cmd = ft_new_cmd("pa");
			start = cmd;
		}
		else
		{
			cmd->next = ft_new_cmd("pa");
			cmd = cmd->next;
		}
		i++;
	}
	return (start);
}

t_lst_cmd	*ft_push_half_b(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	t_lst_cmd	*start;
	t_lst_cmd	*cmd;
	size_t		i;

	start = NULL;
	cmd = NULL;
	i = 0;
	while (i != size / 2)
	{
		ft_p(stack_a, stack_b, 'b');
		if (!cmd)
		{
			cmd = ft_new_cmd("pb");
			start = cmd;
		}
		else
		{
			cmd->next = ft_new_cmd("pb");
			cmd = cmd->next;
		}
		i++;
	}
	return (start);
}
