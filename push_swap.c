/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 15:55:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_are_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (args_are_numbers(ac, av) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stacks = create_stacks(ac);
	if (init_stacks(stacks, ac, av) < 0 || ac < 2)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 2);
	}
	if (has_duplicates(stacks) == 1)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 3);
	}
	if (is_sorted(stacks))
		clean_exit(stacks, 0);
	if (stacks->nb_elem_a <= 3)
		three_elements_sort(stacks);
	else if (stacks->nb_elem_a <= 5)
		five_elements_sort(stacks);
	else
		optimized_sort(stacks);
	clean_exit(stacks, 0);
}
