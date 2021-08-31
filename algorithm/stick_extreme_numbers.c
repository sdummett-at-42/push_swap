/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stick_extreme_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:53:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/31 10:14:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stick(t_stacks * stacks)
{
		unsigned int	i;
	int				min;
	int				max;

	min = get_min_number(stacks);
	max = get_max_number(stacks);

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		if (stacks->a[i] == min || stacks->a[i] == max)
		{
			if (i + 1 == stacks->nb_elem_a)
			{
				if (stacks->a[i - 1] == min || stacks->a[i - 1] == max)
					return (1);
				else if (stacks->a[0] == min || stacks->a[0] == max)
					return (1);
				else
					return (0);
			}
			else if (i == 0)
			{
				if (stacks->a[i + 1] == min || stacks->a[i + 1] == max)
					return (1);
				else if (stacks->a[stacks->nb_elem_a - 1] == min || stacks->a[stacks->nb_elem_a - 1] == max)
					return (1);
				else
					return (0);
			}
			else
			{
				if (stacks->a[i - 1] == min || stacks->a[i - 1] == max)
					return (1);
				else if (stacks->a[i + 1] == min || stacks->a[i + 1] == max)
					return (1);
				else
					return (0);
			}
		}
		i++;
	}
	return (0);
}


void	stick_extreme_numbers(t_stacks *stacks)
{

	printf("nb_elem_a: %d\n", stacks->nb_elem_a);
	if (is_stick(stacks) == 0)
		stick_them(stacks);

}
