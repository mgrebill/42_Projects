/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:07:40 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 15:31:27 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lst_ants	*ft_parse_ants_norme(t_lst_ants *ants, int i)
{
	if (!(ants->next = (t_lst_ants*)malloc(sizeof(t_lst_ants))))
		return (NULL);
	if (!(ants->next->ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ants->next->ant->num = i;
	ants->next->ant->moved = false;
	ants->next->ant->room = NULL;
	ants->next->ant->color =
						(ants->ant->color == 37 ? 31 : ants->ant->color + 1);
	ants = ants->next;
	ants->next = NULL;
	return (ants);
}

t_lst_ants			*ft_parse_ants(char *str)
{
	int			i;
	int			nb_ants;
	t_lst_ants	*start;
	t_lst_ants	*ants;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (NULL);
	i = 1;
	if (!(nb_ants = (int)ft_atoi(str)) ||
			!(ants = (t_lst_ants*)malloc(sizeof(t_lst_ants))))
		return (NULL);
	start = ants;
	if (!(ants->ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ants->ant->num = i;
	ants->ant->moved = false;
	ants->ant->room = NULL;
	ants->ant->color = 31;
	ants->next = NULL;
	while (i++ < nb_ants)
		if (!(ants = ft_parse_ants_norme(ants, i)))
			return (NULL);
	return (start);
}
