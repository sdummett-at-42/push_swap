/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 17:48:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	check_errors_on_args(ac, av);
	stacks = create_stacks(ac);
	check_errors_on_stacks_init(stacks, ac, av);
	check_errors_on_duplicates(stacks);
	if (is_sorted(stacks))
		clean_exit(stacks, 0);
	if (stacks->nb_elem_a <= 3)
		three_elements_sort(stacks);
	else if (stacks->nb_elem_a <= 5)
		five_elements_sort(stacks);
	else
		optimized_sort(stacks);
	clean_exit(stacks, 0);
}
