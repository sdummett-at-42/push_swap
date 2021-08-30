/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:08:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/30 18:36:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Debug function
*/
void	print_med(t_median *med)
{
	unsigned int	i;
	i = 0;
	while (i < med->total)
	{
		printf("[%d]", med->list[i]);
		i++;
	}
	printf("\n");
}

/*
** Init t_median structure
*/

t_median	*init_med(void)
{
	t_median	*new;

	new = malloc(sizeof(t_median));
	if (new == NULL)
		return (NULL);
	new->list = NULL;
	new->total = 0;
	return (new);
}

/*
** Free t_median structure
*/

void	free_med(t_median *med)
{
	free(med->list);
	free(med);
}

/*
** Copy stack a into med.list
*/

void	copy_stack_a(t_stacks *stacks, t_median *med)
{
	unsigned int	i;

	i = stacks->nb_elem_a;
	med->total = stacks->nb_elem_a;
	med->list = malloc(sizeof(int) * med->total);
	while (i > 0)
	{
		med->list[i - 1] = stacks->a[i - 1];
		i--;
	}
}

/*
** Sort the list of numbers
*/

void	sort_med(t_median *med)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;

	i = 0;
	while (i < med->total)
	{
		j = i + 1;
		while (j < med->total)
		{
			if (med->list[i] > med->list[j])
			{
				swap = med->list[j];
				med->list[j] = med->list[i];
				med->list[i] = swap;
			}
			j++;
		}
		i++;
	}
}

/*
** Compute and return the median of the inital stack a
*/

int	get_median(t_stacks *stacks)
{
	t_median				*med;
	unsigned int			index_median;
	int						median;

	med = init_med();
	copy_stack_a(stacks, med);
	sort_med(med);
	index_median = (med->total + 1) / 2;
	if (index_median % 2 == 0)
		median = med->list[index_median - 1];
	else
		median = (med->list[index_median - 1] + med->list[index_median]) / 2;
	free_med(med);
	return (median);
}
