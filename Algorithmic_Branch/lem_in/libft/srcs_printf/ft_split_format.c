/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:57:00 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/06 16:33:14 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_check_percent(const char c)
{
	if (c && (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#' ||
								ft_isdigit(c) || c == '.' || c == 'h' ||
										c == 'l' || c == 'j' || c == 'z'))
		return (true);
	return (false);
}

static int	ft_percent_to_block(const char *format, int i, t_lst_pf *lst)
{
	int		j;

	j = i + 1;
	while (ft_check_percent(format[j]))
		j++;
	if (format[j])
		j++;
	lst->str = ft_strsub(format, i, j - i);
	return (j);
}

static int	ft_normal_str_to_block(const char *format, int i, t_lst_pf *lst)
{
	int		j;

	j = i;
	while (format[j] && format[j] != '%')
		j++;
	lst->str = ft_strsub(format, i, j - i);
	return (j);
}

static void	ft_next(const char *format, int i, t_lst_pf **lst)
{
	if (format[i])
	{
		(*lst)->next = (t_lst_pf*)malloc(sizeof(t_lst_pf));
		*lst = (*lst)->next;
	}
	else
		(*lst)->next = NULL;
}

t_lst_pf	*ft_split_format(const char *format)
{
	int			i;
	t_lst_pf	*start;
	t_lst_pf	*lst;

	i = 0;
	start = (t_lst_pf*)malloc(sizeof(t_lst_pf));
	lst = start;
	while (format[i])
	{
		while (format[i] && format[i] == '%')
		{
			i = ft_percent_to_block(format, i, lst);
			ft_next(format, i, &lst);
		}
		if (format[i] && format[i] != '%')
		{
			i = ft_normal_str_to_block(format, i, lst);
			ft_next(format, i, &lst);
		}
	}
	if (!i && (lst->str = ft_strnew(0)))
		lst->next = NULL;
	return (start);
}
