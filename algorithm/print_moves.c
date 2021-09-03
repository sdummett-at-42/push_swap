/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:06:18 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 12:02:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_gt_b(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	index_a;
	unsigned int	index_b;

	i = 0;
	index_a = stacks->nb_elem_a;
	index_b = stacks->nb_elem_b;
	while (index_a > 0)
	{
		if (index_a > 0)
		{
			printf("index-- : %d | ", index_a - 1);
			printf("%ld", stacks->moves_a[index_a - 1]);
			index_a--;
		}
		else
			printf(" ");
		printf(" ");
		if (index_b > 0 && index_b == index_a + 1)
		{
			printf("%ld\n", stacks->moves_b[index_b - 1]);
			index_b--;
		}
		else
			printf(" \n");
		i++;
	}
	printf("            - -\n");
	printf("            a b\n");
}

static void	stack_b_gt_a(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	index_a;
	unsigned int	index_b;

	i = 0;
	index_a = stacks->nb_elem_a;
	index_b = stacks->nb_elem_b;
	while (index_b > 0)
	{
		if (index_a > 0 && index_a == index_b)
		{
			printf("index-- : %d | ", index_a - 1);
			printf("%ld", stacks->moves_a[index_a - 1]);
			index_a--;
		}
		else
		{
			printf("index-- : %d | ", index_b - 1);
			printf(" ");
		}
		printf(" ");
		if (index_b > 0)
		{
			printf("%ld\n", stacks->moves_b[index_b - 1]);
			index_b--;
		}
		else
			printf(" \n");
		i++;
	}
	printf("            - -\n");
	printf("            a b\n");
}

void	print_moves(t_stacks *stacks)
{
	if (stacks->nb_elem_a > stacks->nb_elem_b)
		return (stack_a_gt_b(stacks));
	return (stack_b_gt_a(stacks));
}
