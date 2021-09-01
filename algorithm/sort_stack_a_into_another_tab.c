/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:52:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/01 12:04:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Debug function
*/
void	print_sorted(t_sorted *sorted)
{
	unsigned int	i;
	i = 0;
	while (i < sorted->total)
	{
		printf("[%d]", sorted->list[i]);
		i++;
	}
	printf("\n");
}

/*
** Init t_sorted structure
*/

t_sorted	*init_med(void)
{
	t_sorted	*new;

	new = malloc(sizeof(t_sorted));
	if (new == NULL)
		return (NULL);
	new->list = NULL;
	new->total = 0;
	return (new);
}

/*
** Copy stack a into med.list
*/

void	copy_stack_a(t_stacks *stacks, t_sorted *sorted)
{
	unsigned int	i;

	i = stacks->nb_elem_a;
	sorted->total = stacks->nb_elem_a;
	sorted->list = malloc(sizeof(int) * sorted->total);
	while (i > 0)
	{
		sorted->list[i - 1] = stacks->a[i - 1];
		i--;
	}
}

/*
** Sort the list of numbers
*/

void	sort_list(t_sorted *sorted)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;

	i = 0;
	while (i < sorted->total)
	{
		j = i + 1;
		while (j < sorted->total)
		{
			if (sorted->list[i] > sorted->list[j])
			{
				swap = sorted->list[j];
				sorted->list[j] = sorted->list[i];
				sorted->list[i] = swap;
			}
			j++;
		}
		i++;
	}
}

t_sorted	*sort_stack_a_into_another_tab(t_stacks *stacks)
{
	t_sorted	*sorted;

	sorted = init_med();
	copy_stack_a(stacks, sorted);
	sort_list(sorted);
	return (sorted);
}