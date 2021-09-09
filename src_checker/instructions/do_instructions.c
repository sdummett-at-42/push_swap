/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:45:03 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:00:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** do_instructions() will perfom all the instructions on the stacks
*/

void	continue_do_instructions(t_stacks *stacks, t_instruc *lst)
{
	if (lst->instruction == RA)
		rotate_a(stacks);
	else if (lst->instruction == RB)
		rotate_b(stacks);
	else if (lst->instruction == RR)
		rotate_a_b(stacks);
	else if (lst->instruction == RRA)
		reverse_rotate_a(stacks);
	else if (lst->instruction == RRB)
		reverse_rotate_b(stacks);
	else if (lst->instruction == RRR)
		reverse_rotate_a_b(stacks);
}

void	do_instructions(t_stacks *stacks, t_instruc *lst)
{
	while (lst != NULL)
	{
		if (lst->instruction == SA)
			swap_a(stacks);
		else if (lst->instruction == SB)
			swap_b(stacks);
		else if (lst->instruction == SS)
			swap_a_b(stacks);
		else if (lst->instruction == PA)
			push_a(stacks);
		else if (lst->instruction == PB)
			push_b(stacks);
		else
			continue_do_instructions(stacks, lst);
		lst = lst->next;
	}
}
