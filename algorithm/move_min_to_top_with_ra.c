/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_to_top_with_ra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:44:10 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 11:51:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top_with_ra(t_stacks *stacks)
{
	int	min_nb;

	min_nb = get_min_number(stacks);
	while (1)
	{
		if (stacks->a[stacks->nb_elem_a - 1] == min_nb)
			break ;
		rotate_a(stacks);
	}
}
