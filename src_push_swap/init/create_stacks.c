/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:57:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 13:05:37 by sdummett         ###   ########.fr       */
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
	stacks->nb_elem_a = ac - 1;
	stacks->nb_elem_a = stacks->nb_elem_a;
	stacks->nb_elem_b = 0;
	stacks->a = malloc(sizeof(int) * stacks->nb_elem_a);
	stacks->b = malloc(sizeof(int) * stacks->nb_elem_a);
	stacks->moves_a = malloc(sizeof(long int) * stacks->nb_elem_a);
	stacks->moves_b = malloc(sizeof(long int) * stacks->nb_elem_a);
	stacks->best_moves = malloc(sizeof(long int *) * stacks->nb_elem_a);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		stacks->best_moves[i] = malloc(sizeof(long int) * 2);
		i++;
	}
	stacks->sorted = NULL;
	return (stacks);
}
