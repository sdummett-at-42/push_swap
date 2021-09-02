/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stick_extreme_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:53:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/02 12:19:27 by sdummett         ###   ########.fr       */
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

void	move_min_rra(t_stacks *stacks)
{
	int	min;

	min = get_min_number(stacks);
	while (stacks->a[stacks->nb_elem_a - 1] != min)
		reverse_rotate_a(stacks);
	if (get_index_max(stacks) > stacks->nb_elem_a - 2)
	{
		while (1)
		{
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
			rotate_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}
	}
	else
	{
		while (1)
		{
			reverse_rotate_a(stacks);
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}		
	}
}

void	move_min_ra(t_stacks *stacks)
{
	int	min;

	min = get_min_number(stacks);
	while (stacks->a[stacks->nb_elem_a - 1] != min)
		rotate_a(stacks);
	if (get_index_max(stacks) > stacks->nb_elem_a - 2)
	{
		while (1)
		{
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
			rotate_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}
	}
	else
	{
		while (1)
		{
			reverse_rotate_a(stacks);
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}		
	}
}

void	move_max_rra(t_stacks *stacks)
{
	int	max;

	max = get_min_number(stacks);
	while (stacks->a[stacks->nb_elem_a - 1] != max)
		reverse_rotate_a(stacks);
	if (get_index_max(stacks) > stacks->nb_elem_a - 2)
	{
		while (1)
		{
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
			rotate_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}
	}
	else
	{
		while (1)
		{
			reverse_rotate_a(stacks);
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}		
	}
}

void	move_max_ra(t_stacks *stacks)
{
	int	max;

	max = get_max_number(stacks);
	while (stacks->a[stacks->nb_elem_a - 1] != max)
		rotate_a(stacks);
	if (get_index_max(stacks) > stacks->nb_elem_a - 2)
	{
		while (1)
		{
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
			rotate_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}
	}
	else
	{
		while (1)
		{
			reverse_rotate_a(stacks);
			swap_a(stacks);
			if (is_stick(stacks) == 1)
				break ;
		}		
	}
}

void	how_to_move_extreme_values(t_stacks *stacks, t_move *move)
{
	unsigned int	i_min;
	unsigned int	i_max;
	unsigned int	diff_to_top_min;
	unsigned int	diff_to_top_max;

	i_min = get_index_min(stacks);
	i_max = get_index_max(stacks);
	// printf("i_min     : %3d | i_max: %3d\n", i_min, i_max);
	diff_to_top_min = (stacks->nb_elem_a - 1) - i_min;
	diff_to_top_max = (stacks->nb_elem_a - 1) - i_max;
	// printf("to_top_min: %3d\n", diff_to_top_min);
	// printf("to_top_max: %3d\n", diff_to_top_max);
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
				move->max_ra = 1; // move_max_ra(stacks);
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

	how_to_move_extreme_values(stacks, &move);
	if (move.min_ra == 1)
		move_min_ra(stacks);
	else if (move.min_rra == 1)
		move_min_rra(stacks);
	else if (move.max_ra == 1)
		move_max_ra(stacks);
	else if (move.max_rra == 1)
		move_max_rra(stacks);
}

int	extreme_are_reversed(t_stacks *stacks)
{
	unsigned int	i_min;
	unsigned int	i_max;

	i_min = get_index_min(stacks);
	i_max = get_index_max(stacks);
	if (i_min == 0)
	{
		if (i_max == 1)
			return (0);
		else
			return (1);
	}
	if (i_min == stacks->nb_elem_a - 1)
	{
		if (i_max == i_min - 1)
			return (1);
		else
			return (0);
	}
	if (i_max == 0)
	{
		if (i_min == 1)
			return (1);
		else
			return (0);
	}
	if (i_max == stacks->nb_elem_a - 1)
	{
		if (i_min == i_max - 1)
			return (0);
		else
			return (1);
	}
	if (i_max < i_min)
		return (1);
	return (0);
}

void	reverse_them(t_stacks *stacks)
{
	unsigned int	i_min;
	unsigned int	i_max;

	write(1, "Do reverse_them()\n", 18);
	i_min = get_index_min(stacks);
	i_max = get_index_max(stacks);
	if (i_min == 0 && i_min != stacks->nb_elem_a - 1)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
	else if (i_min == stacks->nb_elem_a - 1)
		swap_a(stacks);
	else
	{
		rotate_a(stacks);
		swap_a(stacks);
	}
}

void	stick_extreme_numbers(t_stacks *stacks)
{
	if (is_stick(stacks) == 0)
		stick_them(stacks);
	if (extreme_are_reversed(stacks) == 1)
		reverse_them(stacks);
	if (extreme_are_reversed(stacks) == 1) // <- TEMPORARY IN CASE OF BUGS IN reverse_them()
		printf("reverse_them() failed.\n"); 
}
