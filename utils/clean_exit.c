/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:22:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:12:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stacks *stacks)
{
	unsigned int	i;

	i = 0;
	while (i < stacks->nb_elem_total)
	{
		free(stacks->best_moves[i]);
		i++;
	}
	free(stacks->best_moves);
	free(stacks->moves_a);
	free(stacks->moves_b);
	free(stacks->a);
	free(stacks->b);
	free(stacks->sorted->list);
	free(stacks->sorted);
	free(stacks);
	exit(0);
}
