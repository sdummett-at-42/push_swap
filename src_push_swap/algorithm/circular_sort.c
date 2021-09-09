/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:01:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 13:27:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Entry function of the algo that sort big stack
*/

void	circular_sort(t_stacks *stacks)
{
	t_move	move;

	split_until_median(stacks);
	move_stack_a_into_b(stacks);
	while (1)
	{
		count_moves(stacks);
		get_best_moves(stacks);
		move_elem(stacks);
		if (stacks->nb_elem_b == 0)
		{
			move.ra = 0;
			move.rra = 0;
			how_to_sort_circular_sorted_stack(stacks, &move);
			if (move.ra == 1)
				move_min_to_top_with_ra(stacks);
			else if (move.rra == 1)
				move_min_to_top_with_rra(stacks);
			break ;
		}
	}
}
