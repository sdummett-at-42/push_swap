/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/19 18:47:20 by sdummett         ###   ########.fr       */
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
	(void)av;

	stacks = create_stacks(ac);
	init_stacks(stacks, ac, av);
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
	push_b(stacks);
	print_stacks(stacks);
	push_a(stacks);
	print_stacks(stacks);
	push_a(stacks);
	print_stacks(stacks);
	push_a(stacks);
	print_stacks(stacks);
	push_a(stacks);
	print_stacks(stacks);
	push_b(stacks);
	print_stacks(stacks);
	return (0);
}

