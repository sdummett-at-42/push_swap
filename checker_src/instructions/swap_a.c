/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:12:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/31 15:35:03 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Instruction : sa
*/

void	swap_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->nb_elem_a > 1)
	{
		tmp = stacks->a[stacks->nb_elem_a - 1];
		stacks->a[stacks->nb_elem_a - 1] = stacks->a[stacks->nb_elem_a - 2];
		stacks->a[stacks->nb_elem_a - 2] = tmp;
		write(1, "sa\n", 3);
	}
}
