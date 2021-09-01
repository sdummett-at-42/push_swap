/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:18:10 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 10:18:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_index_max(t_stacks *stacks)
{
	unsigned int	i;
	int				max;

	max = get_max_number(stacks);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == max)
			return (i);
		i++;
	}
	return (i);
}
