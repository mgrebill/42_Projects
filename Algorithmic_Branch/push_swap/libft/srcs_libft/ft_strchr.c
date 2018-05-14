/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:31:12 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/15 17:16:03 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	k;
	char	*ptr;

	i = 0;
	k = (char)c;
	ptr = (char *)s;
	while (s[i] && s[i] != k)
	{
		i++;
		ptr++;
	}
	return ((s[i] == c) ? ptr : NULL);
}
