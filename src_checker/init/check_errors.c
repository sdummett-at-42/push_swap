/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:40:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 14:57:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** These functions check errors
*/

void	check_errors_on_args(int ac, char **av)
{
	if (args_are_numbers(ac, av) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_errors_on_stacks_init(t_stacks *stacks, int ac, char **av)
{
	if (init_stacks(stacks, ac, av) < 0 || ac < 2)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 2);
	}	
}

void	check_errors_on_duplicates(t_stacks *stacks)
{
	if (has_duplicates(stacks) == 1)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 3);
	}	
}

void	check_errors_on_instructions(t_instruc *lst, t_stacks *stacks)
{
	if (are_valid_instructions(lst) == 0)
	{
		write(2, "Error\n", 6);
		lst_clear(&lst);
		clean_exit(stacks, 1);
	}
}
