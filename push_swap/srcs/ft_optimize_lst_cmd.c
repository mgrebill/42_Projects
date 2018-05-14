/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_lst_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:43:05 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/28 15:52:45 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_check_doubles(const t_lst_cmd *const cmd)
{
	if (!cmd || !cmd->next)
		return (false);
	if (!ft_strcmp(cmd->str, "pa") && !ft_strcmp(cmd->next->str, "pb"))
		return (true);
	if (!ft_strcmp(cmd->str, "pb") && !ft_strcmp(cmd->next->str, "pa"))
		return (true);
	if (!ft_strcmp(cmd->str, "sa") && !ft_strcmp(cmd->next->str, "sa"))
		return (true);
	if (!ft_strcmp(cmd->str, "sb") && !ft_strcmp(cmd->next->str, "sb"))
		return (true);
	if (!ft_strcmp(cmd->str, "ra") && !ft_strcmp(cmd->next->str, "rra"))
		return (true);
	if (!ft_strcmp(cmd->str, "rra") && !ft_strcmp(cmd->next->str, "ra"))
		return (true);
	if (!ft_strcmp(cmd->str, "rb") && !ft_strcmp(cmd->next->str, "rrb"))
		return (true);
	if (!ft_strcmp(cmd->str, "rrb") && !ft_strcmp(cmd->next->str, "rb"))
		return (true);
	return (false);
}

t_lst_cmd	*ft_optimize_lst_cmd(t_lst_cmd *cmd)
{
	t_lst_cmd	*tmp;

	if (cmd->next)
		cmd->next = ft_optimize_lst_cmd(cmd->next);
	else
		return (cmd);
	if (ft_check_doubles(cmd))
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->str);
		free(tmp);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->str);
		free(tmp);
	}
	return (cmd);
}
