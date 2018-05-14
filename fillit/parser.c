/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:09:53 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 21:15:37 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int			nb_pieces(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char		***ft_tab_tab_tab(char **tab)
{
	char	***megatab;
	int		i;
	int		c;

	i = 0;
	if ((c = nb_pieces(tab)) > 26)
		ft_error();
	megatab = (char ***)malloc(sizeof(char **) * c + 1);
	while (tab[i])
	{
		megatab[i] = ft_strsplit(tab[i], '\n');
		i++;
	}
	megatab[i] = NULL;
	return (megatab);
}

t_tris		*check_parse(char *file)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		r;
	char	***megatab;
	t_tris	*list;

	list = NULL;
	fd = open(file, O_RDONLY);
	r = read(fd, buf, BUFF_SIZE);
	buf[r] = 0;
	if (!(check_coherence(buf)))
		ft_error();
	r = 0;
	megatab = ft_tab_tab_tab(ft_strsplit_nn(buf, '\n'));
	if (!(check_megatab(megatab)))
		ft_error();
	while (megatab[r])
	{
		ft_lst_add_piece_end(&list, ft_lst_new_piece('A' + r, megatab[r]));
		r++;
	}
	return (list);
}
