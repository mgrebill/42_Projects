/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:10:56 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/16 14:56:55 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <limits.h>
# include <fcntl.h>

typedef struct			s_stack
{
	int					*stack;
	size_t				size;
}						t_stack;

typedef struct			s_lst_cmd
{
	void				(*cmd)(t_stack *stack_a, t_stack *stack_b, char stack);
	char				*str;
	struct s_lst_cmd	*next;
	char				stack;
	char				pad__[7];
}						t_lst_cmd;

typedef struct			s_push_mediane_var
{
	t_lst_cmd			*start;
	t_lst_cmd			*cmd;
	size_t				i;
	size_t				r;
	int					mediane;
	char				pad__[4];
}						t_push_mediane_var;

t_stack					*ft_param_to_stack(int argc, char **argv, int i,
																intmax_t nbr);
t_lst_cmd				*ft_stdin_to_lst_cmd(void);
void					ft_s(t_stack *stack_a, t_stack *stack_b, char stack);
void					ft_r(t_stack *stack_a, t_stack *stack_b, char stack);
void					ft_rr(t_stack *stack_a, t_stack *stack_b, char stack);
void					ft_p(t_stack *stack_a, t_stack *stack_b, char stack);
t_lst_cmd				*ft_push_half_a(t_stack *stack_a, t_stack *stack_b,
																size_t size);
t_lst_cmd				*ft_push_half_b(t_stack *stack_a, t_stack *stack_b,
																size_t size);
t_lst_cmd				*ft_push_mediane_a(t_stack *stack_a, t_stack *stack_b,
																size_t size);
t_lst_cmd				*ft_push_mediane_b(t_stack *stack_a, t_stack *stack_b,
																size_t size);
t_stack					*ft_stackalloc(size_t size);
t_stack					*ft_stackndup(t_stack *stack, size_t size);
void					ft_stackdel(t_stack *stack);
t_lst_cmd				*ft_quick_sort_a(t_stack *stack_a, t_stack *stack_b,
																size_t size);
t_lst_cmd				*ft_quick_sort_b(t_stack *stack_a, t_stack *stack_b,
																size_t size);
bool					ft_check_stack(t_stack *stack);
int						ft_find_mediane(t_stack *stack, size_t size);
t_lst_cmd				*ft_optimize_lst_cmd(t_lst_cmd *cmd);
t_lst_cmd				*ft_new_cmd(const char *str);
t_lst_cmd				*ft_little_swap_a(t_stack *stack_a, t_stack *stack_b);
t_lst_cmd				*ft_little_swap_b(t_stack *stack_a, t_stack *stack_b);
t_lst_cmd				*ft_triple_sort_a(t_stack *stack_a, t_stack *stack_b);
t_lst_cmd				*ft_sort_three(t_stack *stack_a, t_stack *stack_b);
t_lst_cmd				*ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void					ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
int						ft_free_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
