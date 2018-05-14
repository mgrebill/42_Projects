/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:52:09 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/18 18:14:41 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	int		i;
	int		j;
	char	*ptr;
	size_t	l;

	i = 0;
	j = 0;
	l = len;
	ptr = (char *)big;
	if (lil[j] == 0 || !ft_strcmp(big, lil))
		return (ptr);
	while (ptr[i] && lil[j] && *ptr && l--)
	{
		j = 0;
		while (ptr[i++] == lil[j] && lil[j] && len--)
			j++;
		if (lil[j])
		{
			ptr++;
			len = l;
			i = 0;
		}
	}
	return ((!lil[j]) ? ptr : NULL);
}
