/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:35:22 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/10 10:44:41 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			d;
	const unsigned char		*str;

	str = (const unsigned char *)s;
	i = 0;
	d = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == d)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
