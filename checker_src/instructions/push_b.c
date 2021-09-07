/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:39:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 02:10:39 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Instruction : pb
*/

void	push_b(t_stacks *stacks)
{
	if (stacks->nb_elem_a > 0)
	{
		stacks->b[stacks->nb_elem_b] = stacks->a[stacks->nb_elem_a - 1];
		stacks->nb_elem_b++;
		stacks->nb_elem_a--;
	}
}
