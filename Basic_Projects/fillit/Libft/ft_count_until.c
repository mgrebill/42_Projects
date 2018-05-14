/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_until.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:50:52 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/20 15:50:56 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_until(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (i);
	else
		return (0);
}