/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:16:34 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/14 13:17:55 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init_ants(t_anthill *anthill)
{
	t_lst_rooms	*rooms;
	t_lst_ants	*ants;

	ants = anthill->ants;
	rooms = anthill->rooms;
	while (!rooms->room->start)
		rooms = rooms->next;
	while (ants)
	{
		ants->ant->room = rooms->room;
		ants = ants->next;
	}
}
