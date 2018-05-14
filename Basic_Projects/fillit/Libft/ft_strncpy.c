/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:16:05 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/05 14:48:09 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	lent;

	i = 0;
	lent = ft_strlen(src);
	while (i < len && i < lent)
	{
		dst[i] = src[i];
		i++;
	}
	if (lent < len)
	{
		while (i < len)
		{
			dst[i] = 0;
			i++;
		}
	}
	return (dst);
}
