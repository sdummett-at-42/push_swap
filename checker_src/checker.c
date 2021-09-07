/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 02:13:05 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	args_are_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
sa | sb | ss | pa | pb | ra | rb | rr | rra | rrb | rrr
*/

int	are_valid_instructions(t_instruc *lst)
{
	int res;

	while (lst != NULL)
	{
		res = 1;
		is_sa(lst, &res);
		is_sb(lst, &res);
		is_ss(lst, &res);
		is_pa(lst, &res);
		is_pb(lst, &res);
		is_ra(lst, &res);
		is_rb(lst, &res);
		is_rr(lst, &res);
		is_rra(lst, &res);
		is_rrb(lst, &res);
		is_rrr(lst, &res);
		if (res == 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	do_instructions(t_stacks *stacks, t_instruc *lst)
{
	while (lst != NULL)
	{
		if (lst->instruction == SA)
			swap_a(stacks);
		else if (lst->instruction == SB)
			swap_b(stacks);
		else if (lst->instruction == SS)
			swap_a_b(stacks);
		else if (lst->instruction == PA)
			push_a(stacks);
		else if (lst->instruction == PB)
			push_b(stacks);
		else if (lst->instruction == RA)
			rotate_a(stacks);
		else if (lst->instruction == RB)
			rotate_b(stacks);
		else if (lst->instruction == RR)
			rotate_a_b(stacks);
		else if (lst->instruction == RRA)
			reverse_rotate_a(stacks);
		else if (lst->instruction == RRB)
			reverse_rotate_b(stacks);
		else if (lst->instruction == RRR)
			reverse_rotate_a_b(stacks);	
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_instruc	*instruc;

	if (ac < 2)
		return (0);
	if (args_are_numbers(ac, av) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stacks = create_stacks(ac);
	if (init_stacks(stacks, ac, av) < 0 || ac < 2)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 2);
	}
	if (has_duplicates(stacks) == 1)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 3);
	}
	instruc = get_instructions();
	if (are_valid_instructions(instruc) == 0)
	{
		write(2, "Error\n", 6);
		lst_clear(&instruc);
		clean_exit(stacks, 1);
	}
	do_instructions(stacks, instruc);
	// check if stacks is sorted and stack b is empty
	if ((stacks->nb_elem_b == 0) && (is_sorted(stacks) == 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3); //stderr or not ?
	lst_clear(&instruc);
	clean_exit(stacks, 0);
	return (0);
}
