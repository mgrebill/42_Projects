/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:55:52 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/05 14:18:29 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	u;
	unsigned char	*s;

	i = 0;
	u = (unsigned char)c;
	s = (unsigned char *)b;
	while (i < len)
		s[i++] = u;
	return (b);
}
