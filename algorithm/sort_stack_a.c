/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:11:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/02 13:18:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stacks *stacks)
{
	int	curr_biggest_nb;
	int	previous_big;

	previous_big = get_max_number(stacks);
	curr_biggest_nb = find_biggest_number(stacks, previous_big);
	while (is_sorted(stacks) != 1)
	{
		// Not sure about this first condition
		// if (stacks->a[stacks->nb_elem_a - 1] > stacks->a[stacks->a[stacks->nb_elem_a - 2]])
		// 	swap_a(stacks);
		// else
		if (is_pseudo_sorted(stacks) == 1)
		{
			t_move_2 move_2;
			move_2.ra = 0;
			move_2.rra = 0;
			how_to_move_pseudo_sorted(stacks, &move_2);
			if (move_2.ra == 1)
				move_min_to_top_with_ra(stacks);
			else if (move_2.rra == 1)
				move_min_to_top_with_rra(stacks);
			if (is_sorted(stacks) == 1)
				break ;
		}
		sort_curr_biggest_number(stacks, curr_biggest_nb, previous_big);
		previous_big = curr_biggest_nb;
		curr_biggest_nb = find_biggest_number(stacks, curr_biggest_nb);
	}
}
