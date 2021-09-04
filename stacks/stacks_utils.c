/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:57:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 12:56:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_stacks(int ac)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->nb_elem_total = ac - 1;
	stacks->nb_elem_a = stacks->nb_elem_total;
	stacks->nb_elem_b = 0;
	stacks->a = malloc(sizeof(int) * stacks->nb_elem_total);
	stacks->b = malloc(sizeof(int) * stacks->nb_elem_total);
	stacks->moves_a = malloc(sizeof(long int) * stacks->nb_elem_total);
	stacks->moves_b = malloc(sizeof(long int) * stacks->nb_elem_total);
	stacks->best_moves = malloc(sizeof(long int *) * stacks->nb_elem_total);
	unsigned int i = 0;
	while (i < stacks->nb_elem_total)
	{
		stacks->best_moves[i] = malloc(sizeof(long int) * 2);
		i++;
	}
	stacks->sorted = NULL;
	return (stacks);
}

int	init_stacks(t_stacks *stacks, int ac, char **av)
{
	unsigned int	i;
	unsigned char	overflow;

	i = 0;
	overflow = 0;
	while (i != stacks->nb_elem_total)
	{
		if (is_number(av[ac - 1]) == 1)
			return (1);
		stacks->a[i] = ft_atoi(av[ac - 1], &overflow);
		if (overflow == 1)
			return (-1);
		ac--;
		i++;
	}
	stacks->sorted = sort_stack_a_into_another_tab(stacks);
	return (0);
}
