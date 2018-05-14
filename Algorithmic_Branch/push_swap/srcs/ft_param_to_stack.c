/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:31:12 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/04 15:56:08 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*ft_argv_to_str(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 2;
	str = ft_strdup(argv[1]);
	while (i < argc)
	{
		str = ft_strjoin_del_one(str, " ");
		str = ft_strjoin_del_one(str, argv[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && !ft_isdigit(str[i]))
			return (NULL);
		i++;
	}
	return (str);
}

static size_t	ft_count_int(char *str)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			size++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (size);
}

static bool		ft_isin(int nbr, size_t i, t_stack *stack)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		if (nbr == stack->stack[j])
			return (true);
		j++;
	}
	return (false);
}

t_stack			*ft_param_to_stack(int argc, char **argv, int i, intmax_t nbr)
{
	char	*argv_str;
	t_stack	*stack;

	if (!(argv_str = ft_argv_to_str(argc, argv)) ||
							!(stack = ft_stackalloc(ft_count_int(argv_str))))
		return (NULL);
	while (argv_str[i])
	{
		if (ft_isdigit(argv_str[i]) || argv_str[i] == '-')
		{
			nbr = ft_atoi(&argv_str[i]);
			if (nbr > INT_MAX || nbr < INT_MIN ||
										ft_isin((int)nbr, stack->size, stack))
				return (NULL);
			stack->stack[stack->size++] = (int)nbr;
			if (argv_str[i] == '-')
				i++;
			while (ft_isdigit(argv_str[i]))
				i++;
		}
		else
			i++;
	}
	free(argv_str);
	return (stack);
}
