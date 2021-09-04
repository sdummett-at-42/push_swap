/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:08:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:30:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Compute and return the median of the inital stack a
*/

int	get_median(t_sorted *sorted)
{
	unsigned int			index_median;
	int						median;

	index_median = (sorted->total + 1) / 2;
	if (index_median % 2 == 0)
		median = sorted->list[index_median - 1];
	else
		median = (sorted->list[index_median - 1] + \
		sorted->list[index_median]) / 2;
	return (median);
}
