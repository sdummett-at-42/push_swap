/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 14:56:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Entry point of checker program
*/

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_instruc	*lst;

	if (ac < 2)
		return (0);
	check_errors_on_args(ac, av);
	stacks = create_stacks(ac);
	check_errors_on_stacks_init(stacks, ac, av);
	check_errors_on_duplicates(stacks);
	lst = get_instructions();
	check_errors_on_instructions(lst, stacks);
	do_instructions(stacks, lst);
	if ((stacks->nb_elem_b == 0) && (is_sorted(stacks) == 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_clear(&lst);
	clean_exit(stacks, 0);
	return (0);
}
