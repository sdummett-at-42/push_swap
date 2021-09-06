/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_opposite_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:09:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 14:16:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	rra(t_stacks *stacks, long int *moves_a)
{
	while (*moves_a != 0)
	{
		reverse_rotate_a(stacks);
		(*moves_a)++;
	}
}

static void	rrb(t_stacks *stacks, long int *moves_b)
{
	while (*moves_b != 0)
	{
		reverse_rotate_b(stacks);
		(*moves_b)++;
	}
}

void	move_opposite_way(t_stacks *stacks, long int moves_a, long int moves_b)
{
	if (moves_a < 0)
		rra(stacks, &moves_a);
	else
		ra(stacks, &moves_a);
	if (moves_b < 0)
		rrb(stacks, &moves_b);
	else
		rb(stacks, &moves_b);
}
