/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_distances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:40:59 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/14 15:19:50 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_set_distances_recursive(t_room *room, int distance)
{
	t_lst_rooms	*tmp;

	tmp = room->connections;
	if (room->distance < 0 || room->distance > distance)
		room->distance = distance;
	while (tmp)
	{
		if (tmp->room->distance < 0 || tmp->room->distance > distance)
			ft_set_distances_recursive(tmp->room, distance + 1);
		tmp = tmp->next;
	}
}

int			ft_set_distances(t_anthill *anthill)
{
	t_lst_rooms	*tmp;

	tmp = anthill->rooms;
	if (!tmp)
		return (0);
	while (!tmp->room->end)
		tmp = tmp->next;
	ft_set_distances_recursive(tmp->room, 0);
	return (42);
}
