/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:17:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 10:17:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_index_min(t_stacks *stacks)
{
	unsigned int	i;
	int				min;


	min = get_min_number(stacks);
	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == min)
			return (i);
		i++;
	}
	return (i);
}
