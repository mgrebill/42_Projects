/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:10:05 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/30 09:39:33 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_coherence(char *s)
{
	int		i;
	int		n;
	int		fig;

	n = 0;
	i = 0;
	fig = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		if (s[i] == '\n')
			n++;
		if (s[i] == '.' || s[i] == '#')
			fig++;
		i++;
	}
	if (i == 20)
		if (fig % 4 == 0 && fig / 4 == n)
			return (1);
	if (fig % 4 == 0 && fig / 4 == (n + 1) - (fig / 16))
		return (1);
	return (0);
}

int		check_prophashdot(char **tab)
{
	int		i;
	int		j;
	int		dot;
	int		hash;

	i = 0;
	dot = 0;
	hash = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				hash++;
			else
				dot++;
			j++;
		}
		i++;
	}
	if (hash == 4 && dot == 12)
		return (1);
	return (0);
}

int		check_content(char *c)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (c[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

int		check_piece(char **piece)
{
	int		i;
	int		j;
	int		att;

	att = 0;
	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#' && i < 3 && piece[i + 1][j] == '#')
				att++;
			if (piece[i][j] == '#' && i > 0 && piece[i - 1][j] == '#')
				att++;
			if (piece[i][j] == '#' && j < 3 && piece[i][j + 1] == '#')
				att++;
			if (piece[i][j] == '#' && j > 0 && piece[i][j - 1] == '#')
				att++;
			j++;
		}
		i++;
	}
	return ((att >= 6));
}

int		check_megatab(char ***megatab)
{
	int		i;

	i = 0;
	while (megatab[i])
	{
		if (!(check_prophashdot(megatab[i])))
			return (0);
		if (!(check_piece(megatab[i])))
			return (0);
		i++;
	}
	return (1);
}
