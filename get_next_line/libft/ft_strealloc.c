/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:20:16 by mgrebill          #+#    #+#             */
/*   Updated: 2016/12/06 17:01:30 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strealloc(char *str, size_t size)
{
	char	*tmp;

	tmp = ft_strdup(str);
	str = ft_strnew(size);
	ft_strcpy(str, tmp);
	return (str);
}
