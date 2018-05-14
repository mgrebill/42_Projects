/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:45:57 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 15:46:31 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_id(t_id *id)
{
	id->flags.minus = false;
	id->flags.zero = false;
	id->flags.plus = false;
	id->flags.blank = false;
	id->flags.sharp = false;
	id->flags.quote = false;
	id->modifiers.hh = false;
	id->modifiers.h = false;
	id->modifiers.l = false;
	id->modifiers.ll = false;
	id->modifiers.z = false;
	id->modifiers.j = false;
	id->dot = false;
	id->mfw = 0;
	id->precision = 0;
	id->type = '\0';
}

static bool	ft_check(char c)
{
	if (c && (c == '-' || c == '0' || c == '+' || c == ' ' ||
			c == '#' || ft_isdigit(c) || c == 'h' || c == 'l' || c == 'j' ||
														c == 'z' || c == '.'))
		return (true);
	return (false);
}

static void	ft_check_flag(char c, t_id *id)
{
	if (c == '-')
		id->flags.minus = true;
	if (c == '0')
		id->flags.zero = true;
	if (c == '+')
		id->flags.plus = true;
	if (c == ' ')
		id->flags.blank = true;
	if (c == '#')
		id->flags.sharp = true;
	if (c == '\'')
		id->flags.quote = true;
}

static void	ft_check_modifier(char *str, int i, t_id *id)
{
	if (str[i] == 'h' && str[i + 1] == 'h' && str[i - 1] != 'h')
		id->modifiers.hh = true;
	if (str[i] == 'h' && str[i - 1] != 'h' && str[i + 1] != 'h')
		id->modifiers.h = true;
	if (str[i] == 'l' && str[i - 1] != 'l' && str[i + 1] != 'l')
		id->modifiers.l = true;
	if (str[i] == 'l' && str[i + 1] == 'l' && str[i - 1] != 'l')
		id->modifiers.ll = true;
	if (str[i] == 'z')
		id->modifiers.z = true;
	if (str[i] == 'j')
		id->modifiers.j = true;
}

t_id		ft_split_identifier(char *str)
{
	int		i;
	t_id	id;

	i = 1;
	ft_init_id(&id);
	while (ft_check(str[i]))
	{
		ft_check_flag(str[i], &id);
		ft_check_modifier(str, i, &id);
		if (str[i] == '.' && (id.dot = true))
			id.precision = 0;
		if (ft_isdigit(str[i]) && str[i] != '0')
		{
			if (id.dot)
				id.precision = ft_atoi(&str[i]);
			else
				id.mfw = ft_atoi(&str[i]);
			while (ft_isdigit(str[i + 1]))
				i++;
		}
		i++;
	}
	id.type = str[i];
	return (id);
}
