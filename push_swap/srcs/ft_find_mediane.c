/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_mediane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:12:40 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/21 17:13:51 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_mediane(t_stack *stack, size_t size)
{
	int		mediane;
	t_stack	*sorted;

	sorted = ft_stackndup(stack, size);
	ft_sort_int_table(sorted->stack, sorted->size);
	mediane = sorted->stack[(sorted->size - 1) / 2];
	ft_stackdel(sorted);
	return (mediane);
}
