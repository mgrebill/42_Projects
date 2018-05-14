/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:51:28 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/19 17:45:05 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_except(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	str[0] = 0;
	return (str);
}

static int	ft_is_whitespaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	ft_sstrlen(char const *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		st;
	int		len;
	char	*str;
	int		i;

	i = 0;
	st = 0;
	len = (int)ft_sstrlen(s) - 1;
	if (len < 0)
		return (ft_except());
	while (s[st] && s[st] != 0 && ft_is_whitespaces(s[st]))
		st++;
	while (len > st && s[len] && s[len] != 0 && ft_is_whitespaces(s[len]))
		len--;
	if (!(str = (char *)malloc(sizeof(char) * (len - st) + 2)))
		return (NULL);
	while (st <= len)
	{
		str[i] = s[st];
		i++;
		st++;
	}
	str[i] = '\0';
	return (str);
}
