/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:22:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 13:03:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Deallocate the memory then exit cleanly
*/

void	clean_exit(t_stacks *stacks, int exit_status)
{
	unsigned int	i;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		free(stacks->best_moves[i]);
		i++;
	}
	free(stacks->best_moves);
	free(stacks->moves_a);
	free(stacks->moves_b);
	free(stacks->a);
	free(stacks->b);
	free(stacks->sorted);
	free(stacks);
	exit(exit_status);
}
