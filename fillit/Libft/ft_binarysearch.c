/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarysearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:23:36 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/16 09:52:05 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
***	Receives a sorted integer array and find the index of desired element
*/

#include "libft.h"

int		ft_binarysearch(int elem, int *tab, int start, int end)
{
	int		pivot;

	pivot = (start + end) / 2;
	if (tab[pivot] == elem)
		return (pivot);
	if (elem > tab[pivot])
		return (ft_binarysearch(elem, tab, pivot, end));
	else
		return (ft_binarysearch(elem, tab, start, pivot));
}
