/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_same_way_bot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:08:07 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 16:04:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Move element of stack A and B to the top of their stack (using rrr if needed)
*/

static void	rrr_a(t_stacks *stacks, long int *moves_a, long int *moves_b)
{
	while (*moves_a != 0)
	{
		reverse_rotate_a_b(stacks);
		(*moves_a)++;
		(*moves_b)++;
	}
}

static void	rrr_b(t_stacks *stacks, long int *moves_a, long int *moves_b)
{
	while (*moves_b != 0)
	{
		reverse_rotate_a_b(stacks);
		(*moves_a)++;
		(*moves_b)++;
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

void	move_same_way_bot(t_stacks *stacks, long int moves_a, long int moves_b)
{
	if (moves_a > moves_b)
	{
		rrr_a(stacks, &moves_a, &moves_b);
		rrb(stacks, &moves_b);
	}
	else
	{
		rrr_b(stacks, &moves_a, &moves_b);
		rra(stacks, &moves_a);
	}
}
