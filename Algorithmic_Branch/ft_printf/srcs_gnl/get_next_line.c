/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:37:25 by mgrebill          #+#    #+#             */
/*   Updated: 2016/12/20 04:27:40 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**static void		ft_del_lst_fd(t_gnl **begin_list)
**{
**	t_gnl	*tmp;
**
**	tmp = (*begin_list);
**	*begin_list = (*begin_list)->next;
**	tmp->next = NULL;
**	free(tmp);
**}
*/

static char		*ft_split_gnl(char *str, char **line)
{
	int		i;
	char	*rest;

	i = 0;
	rest = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] + 1)
		rest = ft_strsub(str, i + 1, ft_strlen(&str[i]));
	(*line) = ft_strsub(str, 0, i);
	return (rest);
}

static t_gnl	*ft_lst_fd(const int fd, t_gnl *begin_list)
{
	t_gnl	*tmp;

	tmp = begin_list;
	if (!tmp)
	{
		if (!(tmp = (t_gnl*)malloc(sizeof(t_gnl))))
			return (NULL);
		tmp->fd = fd;
		tmp->eof = 42;
		tmp->rest = NULL;
		tmp->next = tmp;
		return (tmp);
	}
	while (tmp->next != begin_list && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = NULL;
	if (!(tmp->next = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	tmp->next->fd = fd;
	tmp->next->eof = 42;
	tmp->next->rest = NULL;
	tmp->next->next = begin_list;
	return (tmp->next);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	char			*str;
	static t_gnl	*lst_gnl;

	if (fd < 0 || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	lst_gnl = ft_lst_fd(fd, lst_gnl);
	if (lst_gnl->rest)
		str = ft_strdup(lst_gnl->rest);
	else if (!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	ft_strdel(&lst_gnl->rest);
	while (!ft_strchr(str, '\n') && lst_gnl->eof)
	{
		ft_bzero(buf, BUFF_SIZE);
		if ((lst_gnl->eof = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		str = ft_strjoin_del_one(str, buf);
	}
	ft_strdel(&buf);
	lst_gnl->rest = ft_split_gnl(str, line);
	ft_strdel(&str);
	return ((!lst_gnl->eof && !lst_gnl->rest && !(*line)[0]) ? 0 : 1);
}
