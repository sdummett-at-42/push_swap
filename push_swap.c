/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 19:28:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nb_stacks(t_stacks *stacks)
{
	printf("a : %d | b : %d\n", stacks->nb_elem_a, stacks->nb_elem_b);
	fflush(stdout);
}

int main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = create_stacks(ac);
	if (init_stacks(stacks, ac, av) < 0 || ac < 2)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks);
	}
	if (has_duplicates(stacks) == 1)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks);
	}
	if (is_sorted(stacks))
	{
		print_stacks(stacks);
		//printf("Stack A is already sorted\n"); // <- tmp
		clean_exit(stacks);
	}
//	print_stacks(stacks);
//	ugly_sort(stacks);
	// int res = find_biggest_number(stacks, get_max_number(stacks));
	// printf("biggest nb: %d\n", res);
	// int res_2 = get_number_index(stacks, 9);
	// printf("index: %d\n", res_2);
	sort_curr_biggest_number(stacks, find_biggest_number(stacks, get_max_number(stacks)));
	return (0);

/*
** Implementation of the new algorithm below
*/
	// int median = get_median(stacks->sorted);
	// printf("median is %d\n", median);
	split_until_median(stacks);
	print_sorted(stacks->sorted);
	printf("min       : %3d | max  : %3d\n", get_min_number(stacks), get_max_number(stacks));
	stick_extreme_numbers(stacks);
	if (is_pseudo_sorted(stacks) == 1)
	{
		t_move_2 move_2;
		move_2.ra = 0;
		move_2.rra = 0;
		how_to_move_pseudo_sorted(stacks, &move_2);
		if (move_2.ra == 1)
			move_min_to_top_with_ra(stacks);
		else if (move_2.rra == 1)
			move_min_to_top_with_rra(stacks);
		print_stacks(stacks);
	}

	// else
	// {
	// 	sort_stack_a(stacks);
	// }
	clean_exit(stacks);
}
