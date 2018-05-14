/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:48:41 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 12:50:17 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null(char *str)
{
	str = (char *)malloc(sizeof(1));
	*str = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	char	*end;

	if (!(i = 0) && !s)
		return (NULL);
	end = (char *)s;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (!(str = NULL) && !*s)
		return (ft_null(str));
	while (*(end + 1))
		end++;
	while (*end == ' ' || *end == '\t' || *end == '\n')
		end--;
	end++;
	while (&s[i] != end)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while ((char *)s != end)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
