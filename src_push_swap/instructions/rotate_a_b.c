/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:06:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 16:20:24 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Instruction : rr
*/

void	rr_rotate_a(t_stacks *stacks)
{
	int				tmp;
	unsigned int	i;

	if (stacks->nb_elem_a < 2)
		return ;
	i = stacks->nb_elem_a - 1;
	tmp = stacks->a[i];
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[i] = tmp;
}

void	rr_rotate_b(t_stacks *stacks)
{
	int				tmp;
	unsigned int	i;

	if (stacks->nb_elem_b < 2)
		return ;
	i = stacks->nb_elem_b - 1;
	tmp = stacks->b[i];
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[i] = tmp;
}

void	rotate_a_b(t_stacks *stacks)
{
	rr_rotate_a(stacks);
	rr_rotate_b(stacks);
	write(1, "rr\n", 3);
}
