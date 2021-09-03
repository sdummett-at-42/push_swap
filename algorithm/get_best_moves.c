/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:05:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 11:48:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_best_moves(t_stacks *stacks)
{
	unsigned int	i;

	while (i <= stacks->nb_elem_b / 2)
	{
		stacks->best_moves[0][stacks->nb_elem_b - 1 - i] = get_next_value_index(stacks, stacks->a[stacks->nb_elem_b - 1 - i]);
		if (stacks->moves_a[get_next_value_index(stacks, ...)] < 0 && stacks->)
		stacks->best_moves[1][stacks->nb_elem_b - 1 - i] = stacks->mo;
		i++;
	}
}