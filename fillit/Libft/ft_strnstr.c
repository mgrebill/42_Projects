/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:25:19 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/16 11:30:56 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	e;
	size_t	start;

	i = 0;
	start = 0;
	while (big[i])
	{
		e = 0;
		while (i < len && big[i] == little[e] && big[i] && little[e])
		{
			i++;
			e++;
		}
		if (e == ft_strlen(little))
			return ((char *)&big[i - e]);
		start++;
		i = start;
	}
	return (NULL);
}
