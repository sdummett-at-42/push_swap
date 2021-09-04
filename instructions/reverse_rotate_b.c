/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:17:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:26:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_stacks *stacks)
{
	int				tmp;
	unsigned int	i;

	if (stacks->nb_elem_b < 2)
		return ;
	i = 0;
	tmp = stacks->b[i];
	while (i < stacks->nb_elem_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[i] = tmp;
	write(1, "rrb\n", 4);
}
