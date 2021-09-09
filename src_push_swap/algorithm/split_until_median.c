/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_until_median.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:41:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 12:56:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Useless to enter here if stack a have only 2 numbers
*/

int	get_last_number_at_median(t_stacks *stacks)
{
	int				median;
	int				nb_at_median;
	unsigned int	i;

	median = get_median(stacks->sorted, stacks->nb_elem_a);
	i = 1;
	nb_at_median = median;
	while (i < stacks->nb_elem_a)
	{
		if ((stacks->a[i - 1] > median) && (stacks->a[i - 1] <= nb_at_median))
			nb_at_median = stacks->a[i - 1];
		i++;
	}
	return (nb_at_median);
}

bool	is_splitted(t_stacks *stacks, int nb_at_median)
{
	unsigned int	i;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] <= nb_at_median)
			return (0);
		i++;
	}
	return (1);
}

void	split_until_median(t_stacks *stacks)
{
	int	nb_at_median;

	nb_at_median = get_last_number_at_median(stacks);
	while (is_splitted(stacks, nb_at_median) == false)
	{
		if (stacks->a[stacks->nb_elem_a - 1] <= nb_at_median)
			push_b(stacks);
		else
			rotate_a(stacks);
	}
}
