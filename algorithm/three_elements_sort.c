/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:01:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/05 13:31:55 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elements_sort(t_stacks *stacks)
{
	t_move_2	move_2;

	while (1)
	{
		if (is_pseudo_sorted(stacks))
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
		swap_a(stacks);
	}
}
