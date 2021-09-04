/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:53:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:43:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rr(t_stacks *stacks, long int moves_a, long int moves_b)
{
	if (moves_a < moves_b)
	{
		while (moves_a != 0)
		{
			rotate_a_b(stacks);
			moves_a--;
			moves_b--;
		}
		while (moves_b != 0)
		{
			rotate_b(stacks);
			moves_b--;
		}
	}
	else
	{
		while (moves_b != 0)
		{
			rotate_a_b(stacks);
			moves_b--;
			moves_a--;
		}
		while (moves_a != 0)
		{
			rotate_a(stacks);
			moves_a--;
		}
	}
}

void	move_rrr(t_stacks *stacks, long int moves_a, long int moves_b)
{
	if (moves_a > moves_b)
	{
		while (moves_a != 0)
		{
			reverse_rotate_a_b(stacks);
			moves_a++;
			moves_b++;
		}
		while (moves_b != 0)
		{
			reverse_rotate_b(stacks);
			moves_b++;
		}
	}
	else
	{
		while (moves_b != 0)
		{
			reverse_rotate_a_b(stacks);
			moves_b++;
			moves_a++;
		}
		while (moves_a != 0)
		{
			reverse_rotate_a(stacks);
			moves_a++;
		}
	}
}

void	move_opposite_way(t_stacks *stacks, long int moves_a, long int moves_b)
{
	if (moves_a < 0)
	{
		while (moves_a != 0)
		{
			reverse_rotate_a(stacks);
			moves_a++;
		}
	}
	else
	{
		while (moves_a != 0)
		{
			rotate_a(stacks);
			moves_a--;
		}
	}
	if (moves_b < 0)
	{
		while (moves_b != 0)
		{
			reverse_rotate_b(stacks);
			moves_b++;
		}
	}
	else
	{
		while (moves_b != 0)
		{
			rotate_b(stacks);
			moves_b--;
		}
	}
}

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
		move_rrr(stacks, moves_a, moves_b);
	else if (moves_a >= 0 && moves_b >= 0)
		move_rr(stacks, moves_a, moves_b);
	else
		move_opposite_way(stacks, moves_a, moves_b);
	push_a(stacks);
}
