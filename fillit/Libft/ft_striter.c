/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:45:07 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/15 15:12:56 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	len;
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while ((*f) && i < len)
	{
		f(&(*(s + i)));
		i++;
	}
}
