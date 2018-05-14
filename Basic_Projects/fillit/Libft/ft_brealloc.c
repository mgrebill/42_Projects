/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:36:08 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/20 07:51:12 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_brealloc(void *ptr, size_t size)
{
	void	*tmp;
	int		isnull;

	isnull = 1;
	if (ptr != NULL)
	{
		isnull = 0;
		tmp = ft_memalloc(size);
		ft_memcpy(tmp, ptr, size);
		free(ptr);
	}
	if (!(ptr = malloc(size)))
		return (NULL);
	if (!isnull)
	{
		ft_memcpy(ptr, tmp, size);
		free(tmp);
	}
	return (ptr);
}
