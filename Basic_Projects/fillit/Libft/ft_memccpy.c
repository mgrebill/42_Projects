/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:09:02 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/10 10:44:23 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*dst_c;
	const char		*src_c;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	dst_c = (char *)dst;
	src_c = (const char *)src;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		if (c == src_c[i])
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
