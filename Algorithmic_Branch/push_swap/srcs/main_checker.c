/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:59:23 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/17 14:26:31 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_ok(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stacks(stack_a, stack_b);
	ft_putendl("OK");
	return (0);
}

static int	ft_ko(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stacks(stack_a, stack_b);
	ft_putendl("KO");
	return (0);
}

static int	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stacks(stack_a, stack_b);
	ft_putendl("Error");
	return (42);
}

static void	ft_do_push_swap(t_lst_cmd *push_swap, t_stack *stack_a,
															t_stack *stack_b)
{
	t_lst_cmd	*tmp;

	tmp = NULL;
	while (push_swap)
	{
		push_swap->cmd(stack_a, stack_b, push_swap->stack);
		ft_print_stacks(stack_a, stack_b);
		tmp = push_swap;
		push_swap = push_swap->next;
		free(tmp->str);
		free(tmp);
	}
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_lst_cmd	*push_swap;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!(stack_a = ft_param_to_stack(argc, argv, 0, 0)))
		return (ft_error(stack_a, stack_b));
	if ((!(push_swap = ft_stdin_to_lst_cmd()) && !ft_check_stack(stack_a)) ||
		!(stack_b = ft_stackalloc(stack_a->size)))
		return (ft_error(stack_a, stack_b));
	if (ft_check_stack(stack_a))
		return (ft_ok(stack_a, stack_b));
	ft_print_stacks(stack_a, stack_b);
	ft_do_push_swap(push_swap, stack_a, stack_b);
	if (stack_b->size || !ft_check_stack(stack_a))
		return (ft_ko(stack_a, stack_b));
	return (ft_ok(stack_a, stack_b));
}
