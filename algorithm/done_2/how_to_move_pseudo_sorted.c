/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_move_pseudo_sorted.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:28:03 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 11:42:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	how_to_move_pseudo_sorted(t_stacks *stacks, t_move_2 *move_2)
{
	unsigned int	i_min;

	i_min = get_index_min(stacks);
	if (i_min < (stacks->nb_elem_a - 1) - i_min)
		move_2->rra = 1;
	else
		move_2->ra = 1;
}
