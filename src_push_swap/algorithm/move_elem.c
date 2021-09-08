/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:53:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 15:58:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** It moves an element into stack A in order that stack A is atleast sorted 
** circularly
*/

void	move_elem(t_stacks *stacks)
{
	long int	i_to_move;
	long int	i_elem_a;
	long int	moves_a;
	long int	moves_b;

	i_to_move = get_index_best_moves(stacks);
	i_elem_a = stacks->best_moves[i_to_move][0];
	moves_a = stacks->moves_a[i_elem_a];
	moves_b = stacks->moves_b[i_to_move];
	if (moves_a < 0 && moves_b < 0)
		move_same_way_bot(stacks, moves_a, moves_b);
	else if (moves_a >= 0 && moves_b >= 0)
		move_same_way_top(stacks, moves_a, moves_b);
	else
		move_opposite_way(stacks, moves_a, moves_b);
	push_a(stacks);
}
