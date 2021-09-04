/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_best_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:27:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 12:57:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	get_index_best_moves(t_stacks *stacks)
{
	unsigned int	i;
	long int		index_best_move;

	i = 1;
	index_best_move = 0;
	while (i < stacks->nb_elem_b)
	{
		if (stacks->best_moves[index_best_move][1] > stacks->best_moves[i][1])
			index_best_move = i;
		i++;
	}
	return (index_best_move);
}
