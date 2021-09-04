/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:54:29 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 11:41:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_moves(t_stacks *stacks)
{
	unsigned int	i;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (i >= stacks->nb_elem_a / 2)
			stacks->moves_a[i] = (long int)stacks->nb_elem_a - (long int)i - 1;
		else
			stacks->moves_a[i] = ((long int)i + 1) * -1;
		i++;
	}
	i = 0;
	while (i < stacks->nb_elem_b)
	{
		if (i >= stacks->nb_elem_b / 2)
			stacks->moves_b[i] = (long int)stacks->nb_elem_b - i - 1;
		else
			stacks->moves_b[i] = ((long int)i + 1) * -1;
		i++;
	}
}
