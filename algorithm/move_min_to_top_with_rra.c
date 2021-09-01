/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_to_top_with_rra.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:48:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 11:51:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top_with_rra(t_stacks *stacks)
{
	int	min_nb;

	min_nb = get_min_number(stacks);
	while (1)
	{
		if (stacks->a[stacks->nb_elem_a - 1] == min_nb)
			break ;
		reverse_rotate_a(stacks);
	}
}
