/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:24:50 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 14:26:52 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_connect(t_lst_rooms *room1, t_lst_rooms *room2)
{
	t_lst_rooms	*tmp;

	tmp = NULL;
	tmp = room1->room->connections;
	if (!tmp)
	{
		if (!(tmp = (t_lst_rooms*)malloc(sizeof(t_lst_rooms))))
			return (0);
		tmp->room = room2->room;
		tmp->next = NULL;
		room1->room->connections = tmp;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_lst_rooms*)malloc(sizeof(t_lst_rooms))))
			return (0);
		tmp->next->room = room2->room;
		tmp->next->next = NULL;
	}
	return (42);
}

static int	ft_associate_rooms(char *room1, char *room2, t_lst_rooms *rooms)
{
	t_lst_rooms	*tmp1;
	t_lst_rooms	*tmp2;

	tmp1 = rooms;
	tmp2 = rooms;
	while (tmp1 && ft_strcmp(tmp1->room->name, room1))
		tmp1 = tmp1->next;
	if (!tmp1)
		return (0);
	while (tmp2 && ft_strcmp(tmp2->room->name, room2))
		tmp2 = tmp2->next;
	if (!tmp2)
		return (0);
	if (!(ft_connect(tmp1, tmp2)))
		return (0);
	if (!(ft_connect(tmp2, tmp1)))
		return (0);
	return (42);
}

int			ft_connect_rooms(t_anthill *anthill)
{
	t_lst_tubes	*tmp;

	tmp = anthill->tubes;
	while (tmp)
	{
		if (!(ft_associate_rooms(tmp->tube->room1, tmp->tube->room2,
															anthill->rooms)))
			return (0);
		tmp = tmp->next;
	}
	return (42);
}
