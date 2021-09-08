/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:45:21 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 15:51:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** It returns the index in stack A of a number given as parameter
*/

unsigned int	get_number_index(t_stacks *stacks, int number)
{
	unsigned int	i;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == number)
			return (i);
		i++;
	}
	return (i);
}
