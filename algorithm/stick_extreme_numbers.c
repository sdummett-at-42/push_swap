/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stick_extreme_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:53:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/31 12:07:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stick(t_stacks * stacks)
{
	unsigned int	i;
	int				min;
	int				max;

	min = get_min_number(stacks);
	max = get_max_number(stacks);

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == min || stacks->a[i] == max)
		{
			if (i + 1 == stacks->nb_elem_a)
			{
				if (stacks->a[i - 1] == min || stacks->a[i - 1] == max)
					return (1);
				else if (stacks->a[0] == min || stacks->a[0] == max)
					return (1);
				else
					return (0);
			}
			else if (i == 0)
			{
				if (stacks->a[i + 1] == min || stacks->a[i + 1] == max)
					return (1);
				else if (stacks->a[stacks->nb_elem_a - 1] == min || stacks->a[stacks->nb_elem_a - 1] == max)
					return (1);
				else
					return (0);
			}
			else
			{
				if (stacks->a[i - 1] == min || stacks->a[i - 1] == max)
					return (1);
				else if (stacks->a[i + 1] == min || stacks->a[i + 1] == max)
					return (1);
				else
					return (0);
			}
		}
		i++;
	}
	return (0);
}

unsigned int	get_index_min(t_stacks *stacks)
{
	unsigned int	i;
	int				min;


	min = get_min_number(stacks);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == min)
			return (i);
		i++;
	}
	return (i);
}

unsigned int	get_index_max(t_stacks *stacks)
{
	unsigned int	i;
	int				max;

	max = get_max_number(stacks);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == max)
			return (i);
		i++;
	}
	return (i);
}

void	move_min_rra(t_stacks *stacks)
{
	(void)stacks;
	printf("move_min_rra\n");
}

void	move_min_ra(t_stacks *stacks)
{
	(void)stacks;
	printf("move_min_ra\n");
}

void	move_max_rra(t_stacks *stacks)
{
	(void)stacks;
	printf("move_max_rra\n");
}

void	move_max_ra(t_stacks *stacks)
{
	(void)stacks;
	printf("move_max_ra\n");
}

void	how_to_move(t_stacks *stacks, t_move *move)
{
	unsigned int	i_min;
	unsigned int	i_max;
	unsigned int	diff_to_top_min;
	unsigned int	diff_to_top_max;

	i_min = get_index_min(stacks);
	i_max = get_index_max(stacks);
	printf("i_min: %d | i_max: %d\n", i_min, i_max);
	diff_to_top_min = (stacks->nb_elem_a - 1) - i_min;
	diff_to_top_max = (stacks->nb_elem_a - 1) - i_max;
	printf("to_top_min: %d\n", diff_to_top_min);
	printf("to_top_max: %d\n", diff_to_top_max);
	move->max_ra = 0;
	move->max_rra = 0;
	move->min_ra = 0;
	move->min_rra = 0;
	if (i_min < diff_to_top_min)
	{
		if (i_max < diff_to_top_max)
		{
			if (i_min < i_max)
				 move->min_rra = 1; // move_min_rra(stacks);
			else
				move->max_rra = 1; // move_max_rra(stacks);
		}
		else
		{
			if (i_min < diff_to_top_max)
				move->min_rra = 1; // move_min_rra(stacks);
			else
				move->max_ra = 1; // (stacks);
		}
	}
	else
	{
		if (i_max < diff_to_top_max)
		{
			if (diff_to_top_min < i_max)
				move->min_ra = 1; // move_min_ra(stacks);
			else
				move->max_rra = 1; // move_max_rra(stacks);
		}
		else
		{
			if (diff_to_top_min < diff_to_top_max)
				move->min_ra = 1; // move_min_ra(stacks);
			else
				move->max_ra = 1; // move_max_ra(stacks);
		}
	}
}

void	stick_them(t_stacks *stacks)
{
	t_move			move;

	how_to_move(stacks, &move);
	if (move.min_ra == 1)
		move_min_ra(stacks);
	else if (move.min_rra == 1)
		move_min_rra(stacks);
	else if (move.max_ra == 1)
		move_max_ra(stacks);
	else if (move.max_rra == 1)
		move_max_rra(stacks);
}

void	stick_extreme_numbers(t_stacks *stacks)
{
	printf("nb_elem_a: %d\n", stacks->nb_elem_a);
	if (is_stick(stacks) == 0)
		stick_them(stacks);
}
