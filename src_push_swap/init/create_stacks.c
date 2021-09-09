/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:57:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 12:21:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Create and initialize structure for holding main datas for the algorithm
*/

t_stacks	*create_stacks(int ac)
{
	unsigned int	i;
	t_stacks		*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->nb_elem_total = ac - 1;
	stacks->nb_elem_a = stacks->nb_elem_total;
	stacks->nb_elem_b = 0;
	stacks->a = malloc(sizeof(int) * stacks->nb_elem_total);
	stacks->b = malloc(sizeof(int) * stacks->nb_elem_total);
	stacks->moves_a = malloc(sizeof(long int) * stacks->nb_elem_total);
	stacks->moves_b = malloc(sizeof(long int) * stacks->nb_elem_total);
	stacks->best_moves = malloc(sizeof(long int *) * stacks->nb_elem_total);
	i = 0;
	while (i < stacks->nb_elem_total)
	{
		stacks->best_moves[i] = malloc(sizeof(long int) * 2);
		i++;
	}
	stacks->sorted = NULL;
	return (stacks);
}
