/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:39:31 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/14 10:39:35 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printmsg(char *msg, char *color)
{
	ft_putstr(color);
	ft_putstr(msg);
	ft_putstr(WHITE);
}
