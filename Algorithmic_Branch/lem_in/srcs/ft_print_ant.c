/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:56:38 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/14 18:22:01 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_ant(t_ant ant, bool color)
{
	if (color)
		ft_printf("%kL%u-%s%0k", ant.color, ant.num, ant.room->name);
	else
		ft_printf("L%u-%s", ant.num, ant.room->name);
}
