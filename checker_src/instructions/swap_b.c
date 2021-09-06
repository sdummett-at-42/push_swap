/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 23:13:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 15:23:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Instruction : sb
*/

void	swap_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->nb_elem_b > 1)
	{
		tmp = stacks->b[stacks->nb_elem_a - 1];
		stacks->b[stacks->nb_elem_b - 1] = stacks->b[stacks->nb_elem_a - 2];
		stacks->b[stacks->nb_elem_b - 2] = tmp;
		write(1, "sb\n", 3);
	}
}
