/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/20 18:25:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nb_stacks(t_stacks *stacks)
{
	printf("a : %d | b : %d\n", stacks->nb_elem_a, stacks->nb_elem_b);
	fflush(stdout);
}

// void	parse_args(int ac, char *av)
// {
	
// }

int main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = create_stacks(ac);
	if (init_stacks(stacks, ac, av) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (no_num_dup(stacks) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	print_stacks(stacks);
	// print_nb_stacks(stacks);
	// swap_a(stacks);
	// print_stacks(stacks);
	push_b(stacks);
	print_stacks(stacks);
	push_b(stacks);
	print_stacks(stacks);
	push_b(stacks);
	print_stacks(stacks);
	push_b(stacks);
	print_stacks(stacks);
	rotate_a_b(stacks);
	print_stacks(stacks);
	reverse_rotate_a_b(stacks);
	print_stacks(stacks);
	return (0);
}
