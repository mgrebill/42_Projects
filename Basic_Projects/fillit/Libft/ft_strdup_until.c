/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:01:03 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/20 16:14:15 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_until(char *s, char c)
{
	int		cu;
	int		i;
	char	*ret;

	i = 0;
	cu = ft_count_until(s, c);
	if (!(ret = (char *)ft_memalloc(cu + 1)))
		return (NULL);
	while (i < cu)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
