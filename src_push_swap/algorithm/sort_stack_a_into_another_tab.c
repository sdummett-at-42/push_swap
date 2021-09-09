/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a_into_another_tab.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:52:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 12:55:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Copy stack a into med.list
*/
void	copy_stack_a(int *sorted, t_stacks *stacks)
{
	unsigned int	i;

	i = stacks->nb_elem_a;
	while (i > 0)
	{
		sorted[i - 1] = stacks->a[i - 1];
		i--;
	}
}

/*
** Sort the list of numbers
*/
void	bubble_sort(int *sorted, t_stacks *stacks)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		j = i + 1;
		while (j < stacks->nb_elem_a)
		{
			if (sorted[i] > sorted[j])
			{
				swap = sorted[j];
				sorted[j] = sorted[i];
				sorted[i] = swap;
			}
			j++;
		}
		i++;
	}
}

int	*sort_stack_a_into_another_tab(t_stacks *stacks)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * stacks->nb_elem_a);
	copy_stack_a(sorted, stacks);
	bubble_sort(sorted, stacks);
	return (sorted);
}
