/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_anthill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:09:49 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 15:47:27 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_hub_parser_norme(char *str, bool *ant, bool *tube, bool *room)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i - 1] != ' ')
		{
			*ant = false;
			*tube = true;
		}
		else if (str[i] == ' ')
		{
			*ant = false;
			*room = true;
		}
		else if (!(*tube) && !(*room))
			*ant = true;
		i++;
	}
}

static int	ft_check_str_anthill(char *str, t_anthill *anthill)
{
	if (!ft_strcmp(str, "##start"))
	{
		if (anthill->start == 0 && ++anthill->start)
			return (42);
		else
			return (0);
	}
	else if (!ft_strcmp(str, "##end"))
	{
		if (anthill->end == 0 && ++anthill->end)
			return (42);
		else
			return (0);
	}
	return (42);
}

static void	ft_init_anthill(t_anthill **anthill)
{
	(*anthill)->start = 0;
	(*anthill)->end = 0;
	(*anthill)->tube_manager = 0;
	(*anthill)->room_manager = 0;
	(*anthill)->rooms = NULL;
	(*anthill)->tubes = NULL;
	(*anthill)->ants = NULL;
	(*anthill)->color = false;
}

static int	ft_hub_parser(char *str, t_anthill *anthill)
{
	bool	ant;
	bool	room;
	bool	tube;

	ant = false;
	room = false;
	tube = false;
	if (!ft_check_str_anthill(str, anthill))
		return (0);
	if (str[0] == '#' && str[1] == '#')
		return (42);
	ft_hub_parser_norme(str, &ant, &tube, &room);
	if ((room && anthill->tube_manager) || (tube && !anthill->room_manager))
		return (0);
	if (ant)
		if (!(anthill->ants = ft_parse_ants(str)))
			return (0);
	if (room && ++anthill->room_manager)
		if (!ft_parse_and_manage_rooms(str, anthill))
			return (0);
	if (tube && ++anthill->tube_manager)
		if (!ft_parse_and_manage_tubes(str, anthill))
			return (0);
	return (42);
}

int			ft_parse_anthill(t_anthill **anthill)
{
	char		*str;

	if (!(*anthill = (t_anthill*)malloc(sizeof(t_anthill))))
		return (0);
	ft_init_anthill(anthill);
	str = NULL;
	while (get_next_line(0, &str))
	{
		if (str[0] != '#' || (str[0] == '#' && str[1] == '#'))
			if (!ft_hub_parser(str, *anthill))
			{
				ft_strdel(&str);
				return (0);
			}
		ft_putendl(str);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	if (!(*anthill)->rooms)
		return (0);
	if (!ft_connect_rooms(*anthill))
		return (0);
	return (42);
}
