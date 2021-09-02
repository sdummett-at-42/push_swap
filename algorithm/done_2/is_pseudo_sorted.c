/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pseudo_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:15:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 11:17:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pseudo_sorted(t_stacks *stacks)
{
	long int		i;
	long int		j;
	unsigned int	i_min;
	unsigned int	i_max;

	i_min = get_index_min(stacks);
	i_max = get_index_max(stacks);
	i = i_max;
	j = 1;
	while (i != i_min)
	{
		if (i + 1 > stacks->nb_elem_a - 1)
		{
			if (stacks->a[i] < stacks->a[0])
				return (0);
			i = 0;
		}
		else if (stacks->a[i] < stacks->a[i + 1])
			return (0);
		else
			i++;
		j++;
	}
	if (j != stacks->nb_elem_a)
		return (0);
	return (1);
}
