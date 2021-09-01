/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:11:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 19:38:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stacks *stacks)
{
	int	curr_biggest_nb = find_biggest_number(stacks, get_max_number(stacks));
	while (is_sorted(stacks) != 1)
	{
		// Not sure about this first condition
		if (stacks->a[stacks->nb_elem_a - 1] > stacks->a[stacks->a[stacks->nb_elem_a - 2]])
			swap_a(stacks);
		else
			sort_curr_biggest_nb(stacks, curr_biggest_nb);
	}
}
