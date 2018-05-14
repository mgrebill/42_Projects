/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:41:55 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/26 14:58:49 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst_cmd	*ft_new_cmd(const char *str)
{
	t_lst_cmd	*cmd;

	if (!(cmd = (t_lst_cmd*)malloc(sizeof(t_lst_cmd))))
		return (NULL);
	cmd->str = ft_strdup(str);
	cmd->cmd = NULL;
	cmd->stack = 0;
	cmd->next = NULL;
	return (cmd);
}
