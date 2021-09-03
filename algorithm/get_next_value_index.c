/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_value_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:29:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 19:12:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_next_value_index(t_stacks *stacks, int elem_to_sort)
{
	unsigned int	i;

	if (elem_to_sort > get_max_number(stacks) || elem_to_sort < get_min_number(stacks))
		return (get_index_min(stacks));
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (i == stacks->nb_elem_a - 1)
		{
			if (stacks->a[i] > elem_to_sort && stacks->a[0] < elem_to_sort)
				return (i);
		}
		else if (stacks->a[i] > elem_to_sort && stacks->a[i + 1] < elem_to_sort)
			return (i);
		i++;
	}
	return (i);
}
