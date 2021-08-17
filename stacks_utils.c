/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:57:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/17 20:57:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	index_a;
	unsigned int	index_b;

	i = 0;
	index_a = 0;
	index_b = 0;
	while (i < stacks->nb_elem_total)
	{
		if (index_a < stacks->nb_elem_a)
		{
			printf("%d", stacks->a[index_a]);
			index_a++;
		}
		else
			printf(" ");
		printf(" ");
		if (index_b < stacks->nb_elem_b)
		{
			printf("%d\n", stacks->b[index_b]);
			index_b++;
		}
		else
			printf(" \n");
		i++;
	}
	printf("- -\n");
	printf("a b\n");
}

t_stacks	*create_stacks(int ac)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->nb_elem_total = ac - 1;
	stacks->nb_elem_a = stacks->nb_elem_total;
	stacks->nb_elem_b = 0;
	stacks->a = malloc(sizeof(int) * stacks->nb_elem_total);
	stacks->b = malloc(sizeof(int) * stacks->nb_elem_total);
	return (stacks);
}

void	init_stacks(t_stacks *stacks, char **av)
{
	unsigned int	i;

	i = 0;
	while (i != stacks->nb_elem_total)
	{
		stacks->a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	print_stacks(stacks);
}

