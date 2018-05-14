/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_manage_tubes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:48:52 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 13:18:49 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_parse_and_manage_tubes_norme(t_lst_tubes *tmp, int i, char *str)
{
	int		j;

	if (!(tmp->tube = (t_tube*)malloc(sizeof(t_tube))))
		return (0);
	if (!(tmp->tube->room1 = ft_strsub(str, 0, (size_t)i)))
		return (0);
	while (str[i] && str[i] == '-')
		i++;
	j = i;
	while (str[i])
		i++;
	if (!(tmp->tube->room2 = ft_strsub(str, (unsigned int)j, (size_t)(i - j))))
		return (0);
	return (42);
}

int			ft_parse_and_manage_tubes(char *str, t_anthill *anthill)
{
	int			i;
	t_lst_tubes	*tmp;

	i = 0;
	while (str[i] != '-')
		i++;
	tmp = anthill->tubes;
	if (!tmp)
	{
		if (!(tmp = (t_lst_tubes*)malloc(sizeof(t_lst_tubes))))
			return (0);
		anthill->tubes = tmp;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_lst_tubes*)malloc(sizeof(t_lst_tubes))))
			return (0);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	if (!ft_parse_and_manage_tubes_norme(tmp, i, str))
		return (0);
	return (42);
}
