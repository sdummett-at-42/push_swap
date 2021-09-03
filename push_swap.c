/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 15:52:26 by sdummett         ###   ########.fr       */
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
	
/*
** Implementation of the new algorithm below
*/
	split_until_median(stacks);
	move_stack_a_int_b(stacks);
	count_moves(stacks);
	// print_moves(stacks);
	// print_stacks(stacks);
	while (1)
	{
		get_best_moves(stacks);
		// print_best_moves(stacks);
		move_elem(stacks);
		printf("AFTER MOVING AN ELEM\n");
		print_stacks(stacks);
		if (stacks->nb_elem_b == 0)
		{
			printf("BEFORE FINAL SORT\n");
			print_stacks(stacks);
			t_move_2 move_2;
			move_2.ra = 0;
			move_2.rra = 0;
			how_to_move_pseudo_sorted(stacks, &move_2);
			if (move_2.ra == 1)
				move_min_to_top_with_ra(stacks);
			else if (move_2.rra == 1)
				move_min_to_top_with_rra(stacks);
			printf("AFTER FINAL SORT\n");
			break ;
		}
	}
	if (is_sorted(stacks))
		printf("Congrats\n");
	print_stacks(stacks);
	/* Old algo */
/*
	print_sorted(stacks->sorted);
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
	else
	{
		sort_stack_a(stacks);
	}
	//print_stacks(stacks);
*/
	clean_exit(stacks);
}
