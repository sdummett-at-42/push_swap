/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:31:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 22:48:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_a_gt_b(t_stacks *stacks)
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
			printf("index : %d | ", index_a - 1);
			printf("%d", stacks->a[index_a - 1]);
			index_a--;
		}
		else
			printf(" ");
		printf(" ");
		if (index_b > 0 && index_b == index_a + 1)
		{
			printf("%d\n", stacks->b[index_b - 1]);
			index_b--;
		}
		else
			printf(" \n");
		i++;
	}
	printf("            - -\n");
	printf("            a b\n");
}

void	stack_b_gt_a(t_stacks *stacks)
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
			printf("index : %d | ", index_a - 1);
			printf("%d", stacks->a[index_a - 1]);
			index_a--;
		}
		else
		{
			printf("index : %d | ", index_b - 1);
			printf(" ");
		}
		printf(" ");
		if (index_b > 0)
		{
			printf("%d\n", stacks->b[index_b - 1]);
			index_b--;
		}
		else
			printf(" \n");
		i++;
	}
	printf("            - -\n");
	printf("            a b\n");
}

void	print_stacks(t_stacks *stacks)
{
	if (stacks->nb_elem_a > stacks->nb_elem_b)
		return (stack_a_gt_b(stacks));
	return (stack_b_gt_a(stacks));
}
