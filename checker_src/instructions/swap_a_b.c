/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 23:27:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 15:30:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Instruction : ss
*/

void	ss_swap_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->nb_elem_a > 1)
	{
		tmp = stacks->a[stacks->nb_elem_a - 1];
		stacks->a[stacks->nb_elem_a - 1] = stacks->a[stacks->nb_elem_a - 2];
		stacks->a[stacks->nb_elem_a - 2] = tmp;
	}
}

void	ss_swap_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->nb_elem_b > 1)
	{
		tmp = stacks->b[stacks->nb_elem_a - 1];
		stacks->b[stacks->nb_elem_b - 1] = stacks->b[stacks->nb_elem_a - 2];
		stacks->b[stacks->nb_elem_b - 2] = tmp;
	}
}

void	swap_a_b(t_stacks *stacks)
{
	ss_swap_a(stacks);
	ss_swap_b(stacks);
	write(1, "ss\n", 3);
}
