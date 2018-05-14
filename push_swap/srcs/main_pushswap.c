/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 13:17:26 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/16 14:56:18 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_cmd(t_lst_cmd *lst)
{
	t_lst_cmd	*tmp;
	size_t		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int		ft_print_cmd_lst(t_lst_cmd *lst)
{
	int			fd;
	t_lst_cmd	*tmp;

	tmp = lst;
	lst = lst->next;
	free(tmp->str);
	free(tmp);
	fd = open("./push_swap.log", O_CREAT | O_TRUNC | O_RDWR,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return (42);
	ft_dprintf(fd, "~~~PUSH SWAP LOGFILE~~~\n\n%zu commands\n\n",
															ft_count_cmd(lst));
	while (lst)
	{
		ft_putendl(lst->str);
		ft_putendl_fd(lst->str, fd);
		tmp = lst;
		lst = lst->next;
		free(tmp->str);
		free(tmp);
	}
	close(fd);
	return (0);
}

static void		ft_init_lst(t_lst_cmd *push_swap)
{
	push_swap->str = ft_strdup("Init");
	push_swap->cmd = NULL;
	push_swap->stack = 0;
	push_swap->next = NULL;
}

static int		ft_out_norme(int argc, t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stacks(stack_a, stack_b);
	if (!(argc < 2))
		ft_putendl("Error");
	return (42);
}

int				main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_lst_cmd	*push_swap;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !(stack_a = ft_param_to_stack(argc, argv, 0, 0))
				|| !(stack_b = ft_stackalloc(stack_a->size))
				|| !(push_swap = (t_lst_cmd*)malloc(sizeof(t_lst_cmd))))
		return (ft_out_norme(argc, stack_a, stack_b));
	if (ft_check_stack(stack_a) && !ft_free_stacks(stack_a, stack_b))
	{
		free(push_swap);
		return (0);
	}
	ft_init_lst(push_swap);
	if (stack_a->size == 3)
		push_swap->next = ft_sort_three(stack_a, stack_b);
	else if (stack_a->size == 5)
		push_swap->next = ft_sort_five(stack_a, stack_b);
	else
		push_swap->next = ft_quick_sort_a(stack_a, stack_b, stack_a->size);
	push_swap = ft_optimize_lst_cmd(push_swap);
	ft_free_stacks(stack_a, stack_b);
	return (ft_print_cmd_lst(push_swap));
}
