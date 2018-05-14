/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_to_lst_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:40:27 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/04 16:08:36 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			ft_check_str(char *str)
{
	if (ft_strlen(str) != 2 && ft_strlen(str) != 3)
		return (false);
	if (ft_strlen(str) == 2)
	{
		if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb") && ft_strcmp(str, "ss")
		&& ft_strcmp(str, "ra") && ft_strcmp(str, "rb") && ft_strcmp(str, "rr")
								&& ft_strcmp(str, "pa") && ft_strcmp(str, "pb"))
			return (false);
		else
			return (true);
	}
	else
	{
		if (ft_strcmp(str, "rra") && ft_strcmp(str, "rrb") &&
														ft_strcmp(str, "rrr"))
			return (false);
		else
			return (true);
	}
	return (true);
}

static t_lst_cmd	*ft_str_to_cmd(char *str)
{
	t_lst_cmd	*cmd;

	if (!(cmd = (t_lst_cmd*)malloc(sizeof(t_lst_cmd))))
		return (NULL);
	if (!ft_check_str(str))
		return (NULL);
	if (ft_strlen(str) == 3)
	{
		cmd->stack = str[2];
		cmd->cmd = &ft_rr;
	}
	else
	{
		cmd->stack = str[1];
		if (str[0] == 's')
			cmd->cmd = &ft_s;
		if (str[0] == 'p')
			cmd->cmd = &ft_p;
		if (str[0] == 'r')
			cmd->cmd = &ft_r;
	}
	cmd->str = ft_strdup(str);
	cmd->next = NULL;
	return (cmd);
}

t_lst_cmd			*ft_stdin_to_lst_cmd(void)
{
	char		*str;
	t_lst_cmd	*start;
	t_lst_cmd	*cmd_lst;

	if (!get_next_line(0, &str))
		return (NULL);
	if (!ft_check_str(str))
		return (NULL);
	cmd_lst = ft_str_to_cmd(str);
	start = cmd_lst;
	while (get_next_line(0, &str))
	{
		if (!(cmd_lst->next = ft_str_to_cmd(str)))
			return (NULL);
		cmd_lst = cmd_lst->next;
	}
	free(str);
	cmd_lst->next = NULL;
	return (start);
}
