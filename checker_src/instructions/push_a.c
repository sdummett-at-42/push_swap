/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:33:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 02:10:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Instruction : pa
*/

void	push_a(t_stacks *stacks)
{
	if (stacks->nb_elem_b > 0)
	{
		stacks->a[stacks->nb_elem_a] = stacks->b[stacks->nb_elem_b - 1];
		stacks->nb_elem_a++;
		stacks->nb_elem_b--;
	}
}
