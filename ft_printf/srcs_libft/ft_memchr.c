/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:03:23 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 18:09:09 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	u;
	unsigned char	*str;

	if (c > 255)
		return (NULL);
	u = (unsigned char)c;
	str = (unsigned char *)s;
	while (n - 1 && *str != u && *str++)
		n--;
	return ((*str == u) ? str : NULL);
}
