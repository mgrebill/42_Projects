/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_anthill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:30:44 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 12:30:47 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_free_ants(t_lst_ants *ants)
{
	t_lst_ants	*tmp;

	while (ants)
	{
		tmp = ants;
		ants = ants->next;
		if (tmp->ant)
			free(tmp->ant);
		free(tmp);
	}
}

static void	ft_free_tubes(t_lst_tubes *tubes)
{
	t_lst_tubes	*tmp;

	while (tubes)
	{
		tmp = tubes;
		tubes = tubes->next;
		if (tmp->tube)
		{
			if (tmp->tube->room1)
				free(tmp->tube->room1);
			if (tmp->tube->room2)
				free(tmp->tube->room2);
			free(tmp->tube);
		}
		free(tmp);
	}
}

static void	ft_free_rooms(t_lst_rooms *rooms)
{
	t_lst_rooms	*preco;
	t_lst_rooms	*co;
	t_lst_rooms	*tmp;

	while (rooms)
	{
		tmp = rooms;
		rooms = rooms->next;
		if (tmp->room)
		{
			if (tmp->room->name)
				free(tmp->room->name);
			co = tmp->room->connections;
			while (co)
			{
				preco = co;
				co = co->next;
				free(preco);
			}
			free(tmp->room);
		}
		free(tmp);
	}
}

void		ft_free_anthill(t_anthill *anthill)
{
	if (anthill)
	{
		if (anthill->rooms)
			ft_free_rooms(anthill->rooms);
		if (anthill->tubes)
			ft_free_tubes(anthill->tubes);
		if (anthill->ants)
			ft_free_ants(anthill->ants);
		free(anthill);
	}
}
