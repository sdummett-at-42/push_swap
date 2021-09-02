/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_curr_biggest_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:54:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/02 13:18:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	how_to_move(t_stacks *stacks, t_move_2 *move, int curr_big_nb)
{
	unsigned int	i_curr_nb;

	i_curr_nb = get_number_index(stacks, curr_big_nb);
	if (i_curr_nb < (stacks->nb_elem_a - 1) - i_curr_nb)
		move->rra = 1;
	else
		move->ra = 1;
}

int	is_well_placed(t_stacks *stacks, int curr_big_nb, int next_big_nb)
{
	unsigned int	i_curr_nb;
	unsigned int	i_next_big_nb;

	i_curr_nb = get_number_index(stacks, curr_big_nb);
	i_next_big_nb = get_number_index(stacks, next_big_nb);
	if (i_curr_nb == 0)
	{
		if (i_next_big_nb != stacks->nb_elem_a - 1)
			return (0);
		return (1);
	}
	if (i_next_big_nb != i_curr_nb - 1)
		return (0);
	return (1);
}

void	move_ra(t_stacks *stacks, int curr_big_nb, t_move_2 *move)
{
	while (stacks->a[stacks->nb_elem_a - 1] != curr_big_nb)
		rotate_a(stacks);
	move->ra = 0;
	move->rra = 0;
}

void	move_rra(t_stacks *stacks, int curr_big_nb, t_move_2 *move)
{ 
	while (stacks->a[stacks->nb_elem_a - 1] != curr_big_nb)
		reverse_rotate_a(stacks);
	move->ra = 0;
	move->rra = 0;
}

void	how_to_stick_values(t_stacks * stacks, t_move_2 *move, int curr_big_nb, int next_big_nb)
{
	unsigned int	i_curr_big_nb;
	unsigned int	i_next_big_nb;

	i_curr_big_nb = get_number_index(stacks, curr_big_nb);
	i_next_big_nb = get_number_index(stacks, next_big_nb);
	if (i_curr_big_nb - i_next_big_nb - 1 > i_next_big_nb)
		move->rra = 1;
	else
		move->ra = 1;
}

void	stick_values(t_stacks *stacks, t_move_2 *move, int curr_big_nb, int next_big_nb)
{
	unsigned int	i_curr_big_nb;
	unsigned int	i_next_big_nb;

	i_curr_big_nb = get_number_index(stacks, curr_big_nb);
	i_next_big_nb = get_number_index(stacks, next_big_nb);
	if (move->ra == 1)
	{
		while (1)
		{
			swap_a(stacks);
			if (stacks->a[stacks->nb_elem_a - 3] == next_big_nb)
				break ;
			rotate_a(stacks);
		}
	}
	else if (move->rra == 1)
	{
		while (1)
		{
			reverse_rotate_a(stacks);
			swap_a(stacks);
			if (stacks->a[stacks->nb_elem_a - 2] == next_big_nb)
				break ;
		}
	}
	move->ra = 0;
	move->rra = 0;
}

void	sort_curr_biggest_number(t_stacks *stacks, int curr_big_nb, int next_big_nb)
{
	unsigned int	i;
	t_move_2		move;

	move.ra = 0;
	move.rra = 0;
	how_to_move(stacks, &move, curr_big_nb);
	i = 0;
	if (is_well_placed(stacks, curr_big_nb, next_big_nb) == 0)
	{
		if (move.ra)
			move_ra(stacks, curr_big_nb, &move);
		else if (move.rra == 1)
			move_rra(stacks, curr_big_nb, &move);
		how_to_stick_values(stacks, &move, curr_big_nb, next_big_nb);
		stick_values(stacks, &move, curr_big_nb, next_big_nb);
	}
}
