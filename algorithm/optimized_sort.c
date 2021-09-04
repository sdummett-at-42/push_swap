/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:01:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 17:05:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimized_sort(t_stacks *stacks)
{
	t_move_2	move_2;

	split_until_median(stacks);
	move_stack_a_int_b(stacks);
	while (1)
	{
		count_moves(stacks);
		get_best_moves(stacks);
		move_elem(stacks);
		if (stacks->nb_elem_b == 0)
		{
			move_2.ra = 0;
			move_2.rra = 0;
			how_to_move_pseudo_sorted(stacks, &move_2);
			if (move_2.ra == 1)
				move_min_to_top_with_ra(stacks);
			else if (move_2.rra == 1)
				move_min_to_top_with_rra(stacks);
			break ;
		}
	}
}
