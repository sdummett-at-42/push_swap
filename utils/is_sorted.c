/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:10:35 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:12:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	unsigned int	i;

	i = stacks->nb_elem_a - 1;
	while (i > 0)
	{
		if (stacks->a[i] > stacks->a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
