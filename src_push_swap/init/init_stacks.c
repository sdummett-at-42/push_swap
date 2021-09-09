/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:19:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 13:04:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initialiaze struct s_stacks
*/

int	init_stacks(t_stacks *stacks, int ac, char **av)
{
	unsigned int	i;
	unsigned char	overflow;

	i = 0;
	overflow = 0;
	while (i != stacks->nb_elem_a)
	{
		if (is_number(av[ac - 1]) == false)
			return (1);
		stacks->a[i] = ft_atoi_on_steroid(av[ac - 1], &overflow);
		if (overflow == 1)
			return (-1);
		ac--;
		i++;
	}
	stacks->sorted = sort_stack_a_into_another_tab(stacks);
	return (0);
}
