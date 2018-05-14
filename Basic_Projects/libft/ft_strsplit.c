/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 07:13:36 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 17:40:06 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_words(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static int	ft_lword(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_c_words(s, c) + 1))))
		return (NULL);
	while (s[i] && k < ft_c_words(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (s[i])
			if (!(tab[k] = (char *)malloc(sizeof(char) * (ft_lword(&s[i], c)))))
				return (NULL);
		while (s[i] != c && s[i])
			tab[k][j++] = s[i++];
		tab[k++][j] = '\0';
	}
	if (!(tab[k] = (char *)malloc(sizeof(char))))
		return (NULL);
	tab[k] = NULL;
	return (tab);
}
