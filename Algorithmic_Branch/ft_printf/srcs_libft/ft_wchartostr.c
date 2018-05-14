/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:08:46 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/27 19:21:00 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_one_sized_wchar(wchar_t wc)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (char)wc;
	return (str);
}

static char	*ft_two_sized_wchar(wchar_t wc)
{
	char	*str;

	str = ft_strnew(2);
	str[1] = 128 + (wc % 64);
	wc = wc >> 6;
	str[0] = 192 + (wc % 32);
	return (str);
}

static char	*ft_three_sized_wchar(wchar_t wc)
{
	char	*str;

	str = ft_strnew(3);
	str[2] = 128 + (wc % 64);
	wc = wc >> 6;
	str[1] = 128 + (wc % 64);
	wc = wc >> 6;
	str[0] = 224 + (wc % 16);
	return (str);
}

static char	*ft_four_sized_wchar(wchar_t wc)
{
	char	*str;

	str = ft_strnew(4);
	str[3] = 128 + (wc % 64);
	wc = wc >> 6;
	str[2] = 128 + (wc % 64);
	wc = wc >> 6;
	str[1] = 128 + (wc % 64);
	wc = wc >> 6;
	str[0] = 240 + (wc % 8);
	return (str);
}

char		*ft_wchartostr(wchar_t wc)
{
	if (wc < 128)
		return (ft_one_sized_wchar(wc));
	else if (wc < 2048)
		return (ft_two_sized_wchar(wc));
	else if (wc < 65536)
		return (ft_three_sized_wchar(wc));
	else if (wc < 2097152)
		return (ft_four_sized_wchar(wc));
	else
		return (NULL);
}
