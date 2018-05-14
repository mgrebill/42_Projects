/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:00:11 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 15:49:17 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check(t_anthill *anthill)
{
	t_lst_rooms	*tmp;

	tmp = anthill->rooms;
	while (tmp)
	{
		if (tmp->room->distance < 0)
			return (0);
		tmp = tmp->next;
	}
	return (42);
}

static int	ft_quit_error(t_anthill *anthill)
{
	ft_free_anthill(anthill);
	ft_putendl_error("ERROR");
	return (42);
}

int			main(int argc, char **argv)
{
	t_anthill	*anthill;

	anthill = NULL;
	if (!ft_parse_anthill(&anthill))
		return (ft_quit_error(anthill));
	if (argc > 1)
		if (!ft_strcmp("-c", argv[1]))
			anthill->color = true;
	if (!anthill->rooms || !anthill->ants || !anthill->start || !anthill->end)
		return (ft_quit_error(anthill));
	if (!ft_set_distances(anthill))
		return (ft_quit_error(anthill));
	if (!ft_check(anthill))
		return (ft_quit_error(anthill));
	ft_init_ants(anthill);
	ft_putchar('\n');
	ft_release_the_ants(anthill);
	ft_free_anthill(anthill);
	return (0);
}
