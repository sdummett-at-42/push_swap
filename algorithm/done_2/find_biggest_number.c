/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:32:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/02 13:16:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_number(t_stacks *stacks, int max_nb)
{
	unsigned int	i;
	int				biggest_number;

	i = 1;
	biggest_number = stacks->a[0];
	while (i < stacks->nb_elem_a)
	{
		if ((biggest_number < stacks->a[i] && stacks->a[i] < max_nb) \
		|| (biggest_number >= max_nb && stacks->a[i] < max_nb))
			biggest_number = stacks->a[i];
		i++;
	}
	return (biggest_number);
}
