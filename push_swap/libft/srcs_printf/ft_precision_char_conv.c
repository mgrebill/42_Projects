/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_char_conv.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:53:03 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/05 17:32:58 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_last_unicode(int precision, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= (char)192)
		{
			j = i;
			j++;
			while (str[j] >= (char)128 && str[j] < (char)192)
				j++;
			if (j > precision)
				return (i);
		}
		i++;
	}
	return (i);
}

char		*ft_precision_char_conv(t_id id, char *str)
{
	char	*result;

	if (id.type == 's')
	{
		if (id.precision >= ft_strlen(str))
			return (str);
		result = ft_strsub(str, 0, id.precision);
		free(str);
		return (result);
	}
	if (id.type == 'S')
	{
		result = ft_strsub(str, 0, ft_find_last_unicode(id.precision, str));
		free(str);
		return (result);
	}
	return (str);
}
