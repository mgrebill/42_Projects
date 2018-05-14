/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:34:27 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/11 12:35:03 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	i = stack_a->size - 1;
	while (i)
		ft_printf("%k%d %0k", 32, stack_a->stack[i--]);
	ft_printf("%k%d %0k|", 32, stack_a->stack[i]);
	while (i < stack_b->size)
		ft_printf("%k %d%0k", 31, stack_b->stack[i++]);
	ft_putchar('\n');
	usleep(5000);
}
