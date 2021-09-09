/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:18:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 13:26:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Algo that sorts five elements
*/

void	five_elements_sort(t_stacks *stacks)
{
	t_move	move;

	while (stacks->nb_elem_a != 3)
		push_b(stacks);
	three_elements_sort(stacks);
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
