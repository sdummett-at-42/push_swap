/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pseudo_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:15:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 14:40:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pseudo_sorted(t_stacks *stacks)
{
	long int		i;
	unsigned int	i_min;
	unsigned int	i_max;

	i_min = get_index_min(stacks);
	i_max = get_index_max(stacks);
	i = 1;
	while (i_max != i_min)
	{
		if (i_max + 1 > stacks->nb_elem_a - 1)
		{
			if (stacks->a[i_max] < stacks->a[0])
				return (0);
			i_max = 0;
		}
		else if (stacks->a[i_max] < stacks->a[i_max + 1])
			return (0);
		else
			i_max++;
		i++;
	}
	if (i != stacks->nb_elem_a)
		return (0);
	return (1);
}
