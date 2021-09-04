/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:05:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:51:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_best_moves(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	i_next_elem;

	i = 0;
	while (i < stacks->nb_elem_b)
	{
		i_next_elem = get_next_value_index(stacks, stacks->b[i]);
		stacks->best_moves[i][0] = i_next_elem;
		if (stacks->moves_a[i_next_elem] < 0 && stacks->moves_b[i] < 0)
		{
			if (stacks->moves_a[i_next_elem] > stacks->moves_b[i])
				stacks->best_moves[i][1] = (stacks->moves_b[i] * -1);
			else
				stacks->best_moves[i][1] = stacks->moves_a[i_next_elem] * -1;
		}
		else if (stacks->moves_a[i_next_elem] >= 0 && stacks->moves_b[i] >= 0)
		{
			if (stacks->moves_a[i_next_elem] > stacks->moves_b[i])
				stacks->best_moves[i][1] = stacks->moves_a[i_next_elem];
			else
				stacks->best_moves[i][1] = stacks->moves_b[i];
		}
		else
		{
			if (stacks->moves_a[i_next_elem] < 0 )
				stacks->best_moves[i][1] = (stacks->moves_a[i_next_elem] * -1) \
				+ stacks->moves_b[i];
			else
				stacks->best_moves[i][1] = stacks->moves_a[i_next_elem] \
				+ (stacks->moves_b[i] * -1);
		}
		i++;
	}
}
