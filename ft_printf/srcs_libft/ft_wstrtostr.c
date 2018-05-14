/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:15:41 by mgrebill          #+#    #+#             */
/*   Updated: 2017/08/06 16:25:54 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtostr(wchar_t *ws)
{
	char	*str;
	int		i;

	if (!ws)
		return (NULL);
	if (!ws[0])
		return (ft_strdup("\0"));
	i = 1;
	str = ft_wchartostr(ws[0]);
	while (ws[i])
	{
		str = ft_strjoin_del_both(str, ft_wchartostr(ws[i]));
		i++;
	}
	return (str);
}
