/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:18:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/05 13:27:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_elements_sort(t_stacks *stacks)
{
	t_move_2	move_2;

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
