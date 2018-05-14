/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:13:48 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/30 14:44:24 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_custom_strlen(char const *s, char c)
{
	int		e;

	e = 0;
	while ((s[e] && s[e] != c) || (s[e + 1] && s[e + 1] != c))
		e++;
	return (e);
}

static int			ft_count_words(char const *s, char c)
{
	int		e;
	int		count;

	e = 0;
	count = 0;
	if (s[0] != c && s[1] != c && s[0])
		count++;
	while (s[e] && s[e + 1])
	{
		if (s[e] == c && s[e + 1] == c && (s[e + 2] != c || s[e + 2] == '\0'))
			count++;
		e++;
	}
	return (count);
}

static void			cpy_words(char *dst, char const *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char				**ft_strsplit_nn(char const *s, char c)
{
	int		words;
	char	**tab;
	size_t	len;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = ft_count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * words + 1)))
		return (NULL);
	while (i < words)
	{
		while (*s == c && *(s + 1) == c)
			s++;
		len = ft_custom_strlen(s, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		cpy_words(tab[i], s, len);
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
