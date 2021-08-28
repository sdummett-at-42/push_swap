/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:42:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/28 21:48:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stacks *stacks)
{
	int				smallest;
	unsigned int	i;
	
	i = stacks->nb_elem_a;
	smallest = stacks->a[i - 1];
	while (i > 1)
	{

		if (stacks->a[i - 2] < smallest)
			smallest = stacks->a[i - 2];
	
		i--;
	}
	return (smallest);
}

void	refill_stack_a(t_stacks *stacks)
{
	while (stacks->nb_elem_b > 0)
		push_a(stacks);
	clean_exit(stacks);
}

void	ugly_sort(t_stacks *stacks)
{
	int smallest_nb;

	smallest_nb = find_smallest(stacks);
	while (1)
	{
		if (stacks->nb_elem_a == 0)
			refill_stack_a(stacks);
		if (stacks->nb_elem_a > 1)
		{
			while (stacks->a[stacks->nb_elem_a - 1] != smallest_nb)
				reverse_rotate_a(stacks);
		}
		push_b(stacks);
		if (stacks->nb_elem_a > 1)
			smallest_nb = find_smallest(stacks);
	}
}
