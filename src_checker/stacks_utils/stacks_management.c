/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:06:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 23:06:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stacks	*create_stacks(int ac)
{
	unsigned int	total;
	t_stacks		*stacks;

	stacks = malloc(sizeof(t_stacks));
	total = ac - 1;
	stacks->nb_elem_a = total;
	stacks->nb_elem_b = 0;
	stacks->a = malloc(sizeof(int) * total);
	stacks->b = malloc(sizeof(int) * total);
	return (stacks);
}

int	init_stacks(t_stacks *stacks, int ac, char **av)
{
	unsigned int	i;
	unsigned int	total;
	unsigned char	overflow;

	i = 0;
	overflow = 0;
	total = ac - 1;
	while (i < total)
	{
		if (is_number(av[ac - 1]) == 0)
			return (1);
		stacks->a[i] = ft_atoi_on_steroid(av[ac - 1], &overflow);
		if (overflow == 1)
			return (-1);
		ac--;
		i++;
	}
	return (0);
}
