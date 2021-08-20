/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_num_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:27:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/20 17:28:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_num_dup(t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		j = i + 1;
		while (j < stacks->nb_elem_a)
		{
			if (stacks->a[i] == stacks->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
