/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:57:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/20 18:32:25 by sdummett         ###   ########.fr       */
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
			return (1);
		ac--;
		i++;
	}
	return (0);
}
