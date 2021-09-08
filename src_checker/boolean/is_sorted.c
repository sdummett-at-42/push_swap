/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:10:35 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 14:34:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_stacks *stacks)
{
	unsigned int	i;

	if (stacks->nb_elem_a > 0)
	{
		i = stacks->nb_elem_a - 1;
		while (i > 0)
		{
			if (stacks->a[i] > stacks->a[i - 1])
			{
				return (0);
			}
			i--;
		}
		return (1);
	}
	return (0);
}
