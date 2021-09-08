/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_same_way_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:06:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 16:04:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Move element of stack A and B to the top of their stack (using rr if needed)
*/

static void	rr_a(t_stacks *stacks, long int *moves_a, long int *moves_b)
{
	while (*moves_a != 0)
	{
		rotate_a_b(stacks);
		(*moves_a)--;
		(*moves_b)--;
	}
}

static void	rr_b(t_stacks *stacks, long int *moves_a, long int *moves_b)
{
	while (*moves_b != 0)
	{
		rotate_a_b(stacks);
		(*moves_a)--;
		(*moves_b)--;
	}
}

static void	ra(t_stacks *stacks, long int *moves_a)
{
	while (*moves_a != 0)
	{
		rotate_a(stacks);
		(*moves_a)--;
	}
}

static void	rb(t_stacks *stacks, long int *moves_b)
{
	while (*moves_b != 0)
	{
		rotate_b(stacks);
		(*moves_b)--;
	}
}

void	move_same_way_top(t_stacks *stacks, long int moves_a, long int moves_b)
{
	if (moves_a < moves_b)
	{
		rr_a(stacks, &moves_a, &moves_b);
		rb(stacks, &moves_b);
	}
	else
	{
		rr_b(stacks, &moves_a, &moves_b);
		ra(stacks, &moves_a);
	}
}
