/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_release_the_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:56:25 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/14 18:42:58 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_ants_moved(t_lst_ants *ants, bool color)
{
	t_lst_ants	*tmp;

	tmp = ants;
	while (tmp)
	{
		if (tmp->ant->moved)
		{
			ft_print_ant(*tmp->ant, color);
			ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static void	ft_reset_ants(t_lst_ants *ants)
{
	t_lst_ants	*tmp;

	tmp = ants;
	while (tmp)
	{
		tmp->ant->moved = false;
		tmp = tmp->next;
	}
}

static bool	ft_check_ants(t_lst_ants *ants)
{
	t_lst_ants	*tmp;

	tmp = ants;
	while (tmp)
	{
		if (!tmp->ant->room->end)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static void	ft_move_ant_short(t_ant *ant)
{
	t_lst_rooms	*co;
	int			smaller;

	co = ant->room->connections;
	smaller = co->room->distance;
	while (co)
	{
		if (co->room->distance < smaller)
			smaller = co->room->distance;
		co = co->next;
	}
	co = ant->room->connections;
	while (co->room->distance != smaller)
		co = co->next;
	if (!co->room->ant)
	{
		if (!co->room->end)
			co->room->ant = true;
		ant->room->ant = false;
		ant->room = co->room;
		ant->moved = true;
	}
}

void		ft_release_the_ants(t_anthill *anthill)
{
	t_lst_ants	*ants;

	ants = anthill->ants;
	while (!ft_check_ants(ants))
	{
		ft_reset_ants(ants);
		while (ants)
		{
			ft_move_ant_short(ants->ant);
			ants = ants->next;
		}
		ants = anthill->ants;
		ft_print_ants_moved(ants, anthill->color);
	}
}
