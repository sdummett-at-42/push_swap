/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 16:43:13 by sdummett         ###   ########.fr       */
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

t_stacks	*create_stacks(int ac)
{
	unsigned int	total;
	t_stacks		*stacks;

	stacks = malloc(sizeof(t_stacks));
	total = ac - 1;
	stacks->nb_elem_a = total;
	stacks->nb_elem_b = 0;
	stacks->a = malloc(sizeof(int) * total);
	stacks->b = malloc(sizeof(int) * total);
	return (stacks);
}

int	init_stacks(t_stacks *stacks, int ac, char **av)
{
	unsigned int	i;
	unsigned int	total;
	unsigned char	overflow;

	i = 0;
	overflow = 0;
	total = ac - 1;
	while (i < total)
	{
		if (is_number(av[ac - 1]) == 0)
			return (1);
		stacks->a[i] = ft_atoi_on_steroid(av[ac - 1], &overflow);
		printf("I : %d | a : %d | ac : %d\n", i, stacks->a[i], ac);
		if (overflow == 1)
			return (-1);
		ac--;
		i++;
	}
	return (0);
}

void	print_stacks(t_stacks * stacks)
{
	unsigned int	i;

	i = 0;
	while (i < stacks->nb_elem_a)
	{
		printf("index => %d [%d]\n", i, stacks->a[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

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
	print_stacks(stacks);
	return (0);
}
