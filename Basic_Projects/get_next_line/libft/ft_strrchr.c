/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:58:03 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/15 17:17:41 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	k;
	char	*ptr;

	k = (char)c;
	len = ft_strlen(s);
	ptr = (char *)&s[len];
	while (len && s[len] != k)
	{
		ptr--;
		len--;
	}
	return ((s[len] == c) ? ptr : NULL);
}
