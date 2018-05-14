/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:18:36 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/10 17:25:17 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	int		tmp;

	len = ft_strlen(s);
	tmp = (int)len;
	while (tmp != -1)
	{
		if (s[tmp] == (char)c)
			return ((char *)&s[tmp]);
		tmp--;
	}
	return (NULL);
}
