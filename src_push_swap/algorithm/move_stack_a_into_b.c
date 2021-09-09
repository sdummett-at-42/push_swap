/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a_into_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:27:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:20:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** It moves all the element of stack A into B leaving only two elements
*/

void	move_stack_a_into_b(t_stacks *stacks)
{
	while (stacks->nb_elem_a != 2)
		push_b(stacks);
}
