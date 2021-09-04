/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extreme_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:37:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 20:14:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_number(t_stacks *stacks)
{
	unsigned int	i;
	int				min;

	i = 1;
	min = stacks->a[0];
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] < min)
			min = stacks->a[i];
		i++;
	}
	return (min);
}

int	get_max_number(t_stacks *stacks)
{
	unsigned int	i;
	int				max;

	i = 1;
	max = stacks->a[0];
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] > max)
			max = stacks->a[i];
		i++;
	}
	return (max);
}
