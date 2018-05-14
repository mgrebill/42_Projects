/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_manage_rooms.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:10:10 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 15:57:09 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_parse_and_manage_rooms_norme(t_lst_rooms *tmp,
										t_anthill *anthill, int i, char *str)
{
	tmp->next = NULL;
	if (!(tmp->room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	if (!(tmp->room->name = ft_strsub(str, 0, (size_t)i)))
		return (0);
	tmp->room->start = (anthill->start == 1);
	tmp->room->end = (anthill->end == 1);
	tmp->room->distance = -1;
	tmp->room->ant = false;
	tmp->room->connections = NULL;
	anthill->start += (anthill->start == 1);
	anthill->end += (anthill->end == 1);
	i++;
	tmp->room->x = (int)ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	tmp->room->y = (int)ft_atoi(&str[i]);
	return (42);
}

static int	ft_parse_blablabla_norme_le_retour(t_lst_rooms **tmp, char *str)
{
	while ((*tmp)->next)
	{
		if (!ft_strcmp(str, (*tmp)->room->name))
			return (0);
		(*tmp) = (*tmp)->next;
	}
	if (!((*tmp)->next = (t_lst_rooms*)malloc(sizeof(t_lst_rooms))))
		return (0);
	(*tmp) = (*tmp)->next;
	return (42);
}

int			ft_parse_and_manage_rooms(char *str, t_anthill *anthill)
{
	int			i;
	t_lst_rooms	*tmp;

	if ((!(i = 0) && !str) || str[0] == 'L')
		return (0);
	while (str[i] != ' ')
		i++;
	if (!(tmp = anthill->rooms))
	{
		if (!(tmp = (t_lst_rooms*)malloc(sizeof(t_lst_rooms))))
			return (0);
		anthill->rooms = tmp;
	}
	else if (!ft_parse_blablabla_norme_le_retour(&tmp, str))
		return (0);
	if (!ft_parse_and_manage_rooms_norme(tmp, anthill, i, str))
		return (0);
	return (42);
}
