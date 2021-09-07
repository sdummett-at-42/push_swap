/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:27:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 18:06:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	has_duplicates(t_stacks *stacks)
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
