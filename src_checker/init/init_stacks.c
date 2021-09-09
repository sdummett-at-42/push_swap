/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:24:05 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:03:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Initialiaze struct s_stacks
*/

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
