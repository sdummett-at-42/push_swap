/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extreme_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:18:10 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 15:49:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** It returns the index of the actual minimum or maximum number in stack A
*/

unsigned int	get_index_min(t_stacks *stacks)
{
	unsigned int	i;
	int				min;

	min = get_min_number(stacks);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == min)
			return (i);
		i++;
	}
	return (i);
}

unsigned int	get_index_max(t_stacks *stacks)
{
	unsigned int	i;
	int				max;

	max = get_max_number(stacks);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == max)
			return (i);
		i++;
	}
	return (i);
}
