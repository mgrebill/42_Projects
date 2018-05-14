/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:13:35 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/15 17:18:19 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lil)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)big;
	if (lil[j] == 0)
		return ((char *)big);
	if (!ft_strcmp(big, lil))
		return (ptr);
	while (ptr[i] && lil[j] && *ptr)
	{
		j = 0;
		while (ptr[i++] == lil[j] && lil[j])
			j++;
		if (lil[j])
		{
			ptr++;
			i = 0;
		}
	}
	return ((!lil[j]) ? ptr : NULL);
}
