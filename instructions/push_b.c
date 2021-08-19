/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:39:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/19 18:15:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Instruction : pb
*/

void	push_b(t_stacks *stacks)
{
	if (stacks->nb_elem_a > 0)
	{
		stacks->b[stacks->nb_elem_b] = stacks->a[stacks->nb_elem_a - 1];
		stacks->nb_elem_b++;
		stacks->nb_elem_a--;
		write(1, "pb\n", 3);
	}
}
