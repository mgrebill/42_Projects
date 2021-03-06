/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:28:36 by mgrebill          #+#    #+#             */
/*   Updated: 2016/11/21 17:51:39 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_str(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strdup(s1);
	s1 = ft_strcpy(s1, s2);
	s2 = ft_strcpy(s2, tmp);
	free(tmp);
}
