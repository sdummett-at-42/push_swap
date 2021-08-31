/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/31 10:08:52 by sdummett         ###   ########.fr       */
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

/*
** Implementation of the new algorithm below
*/
	// int median = get_median(stacks->sorted);
	// printf("median is %d\n", median);
	split_until_median(stacks);
	print_sorted(stacks->sorted);
	int min = get_min_number(stacks);
	int max = get_max_number(stacks);
	printf("min: %d | max: %d\n", min, max);
	stick_extreme_numbers(stacks);
	clean_exit(stacks);
}
