/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_sort_circular_sorted_stack.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:28:03 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 15:59:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks wich is the best way to move min number to top of stack A
*/

void	how_to_sort_circular_sorted_stack(t_stacks *stacks, t_move_2 *move_2)
{
	unsigned int	i_min;

	i_min = get_index_min(stacks);
	if (i_min < stacks->nb_elem_a / 2)
		move_2->rra = 1;
	else
		move_2->ra = 1;
}
