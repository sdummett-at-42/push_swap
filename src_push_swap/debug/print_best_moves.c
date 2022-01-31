/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_best_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:59:50 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/03 14:47:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_best_moves(t_stacks *stacks)
{
	unsigned int	total;

	if (stacks->nb_elem_a > stacks->nb_elem_b)
		total = stacks->nb_elem_a;
	else
		total = stacks->nb_elem_b;
	while (total > 0)
	{
		printf("total: %3d | %4ld | %4ld |\n", total - 1, stacks->best_moves[0][total - 1], stacks->best_moves[1][total - 1]);
		total--;
	}
}
