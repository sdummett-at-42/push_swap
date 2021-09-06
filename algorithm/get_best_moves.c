/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:05:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 14:31:44 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_best_moves(t_stacks *stacks, unsigned int *i, \
unsigned int *i_next)
{
	if (stacks->moves_a[(*i_next)] < 0 && stacks->moves_b[(*i)] < 0)
	{
		if (stacks->moves_a[(*i_next)] > stacks->moves_b[(*i)])
			stacks->best_moves[(*i)][1] = (stacks->moves_b[(*i)] * -1);
		else
			stacks->best_moves[(*i)][1] = stacks->moves_a[(*i_next)] * -1;
	}
	else if (stacks->moves_a[(*i_next)] >= 0 && stacks->moves_b[(*i)] >= 0)
	{
		if (stacks->moves_a[(*i_next)] > stacks->moves_b[(*i)])
			stacks->best_moves[(*i)][1] = stacks->moves_a[(*i_next)];
		else
			stacks->best_moves[(*i)][1] = stacks->moves_b[(*i)];
	}
	else
	{
		if (stacks->moves_a[(*i_next)] < 0 )
			stacks->best_moves[(*i)][1] = (stacks->moves_a[(*i_next)] * -1) \
			+ stacks->moves_b[(*i)];
		else
			stacks->best_moves[(*i)][1] = stacks->moves_a[(*i_next)] \
			+ (stacks->moves_b[(*i)] * -1);
	}
}

void	get_best_moves(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	i_next_elem;

	i = 0;
	while (i < stacks->nb_elem_b)
	{
		i_next_elem = get_next_value_index(stacks, stacks->b[i]);
		stacks->best_moves[i][0] = i_next_elem;
		compute_best_moves(stacks, &i, &i_next_elem);
		i++;
	}
}
