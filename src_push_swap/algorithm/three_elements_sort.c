/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:01:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 16:26:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Entry function that sorts one, two or three elements
*/

void	three_elements_sort(t_stacks *stacks)
{
	t_move_2	move_2;

	while (1)
	{
		if (is_circular_sorted(stacks))
		{
			move_2.ra = 0;
			move_2.rra = 0;
			how_to_sort_circular_sorted_stack(stacks, &move_2);
			if (move_2.ra == 1)
				move_min_to_top_with_ra(stacks);
			else if (move_2.rra == 1)
				move_min_to_top_with_rra(stacks);
			break ;
		}
		swap_a(stacks);
	}
}
