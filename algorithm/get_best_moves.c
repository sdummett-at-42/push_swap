/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:05:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 19:12:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_best_moves(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	next_elem_index;
	unsigned int	current_index;

	i = 0;
	while (i < stacks->nb_elem_b )//<= stacks->nb_elem_b / 2)
	{
		current_index = stacks->nb_elem_b - i - 1;
		next_elem_index = get_next_value_index(stacks, stacks->b[current_index]);
		stacks->best_moves[0][i] = next_elem_index;
		if (stacks->moves_a[next_elem_index] < 0 && stacks->moves_b[current_index] < 0)
		{
			if (stacks->moves_a[next_elem_index] > stacks->moves_b[current_index])
				stacks->best_moves[1][i] = (stacks->moves_b[current_index] * -1);
			else
				stacks->best_moves[1][i] = stacks->moves_a[next_elem_index] * -1;
		}
		else if (stacks->moves_a[next_elem_index] >= 0 && stacks->moves_b[current_index] >= 0)
		{
			if (stacks->moves_a[next_elem_index] > stacks->moves_b[current_index])
				stacks->best_moves[1][i] = stacks->moves_a[next_elem_index];
			else
				stacks->best_moves[1][i] = stacks->moves_b[current_index];
		}
		else
		{
			if (stacks->moves_a[next_elem_index] < 0 )
				stacks->best_moves[1][i] = (stacks->moves_a[next_elem_index] * -1) + stacks->moves_b[current_index];
			else
				stacks->best_moves[1][i] = stacks->moves_a[next_elem_index] + (stacks->moves_b[current_index] * -1);
		}
		i++;
	}
}
