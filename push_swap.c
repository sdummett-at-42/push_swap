/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:39:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/16 20:58:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stacks(int ac)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	stacks->nb_elem = ac - 1;
	stacks->a = malloc(sizeof(int) * stacks->nb_elem);
	stacks->b = malloc(sizeof(int) * stacks->nb_elem);
	return (stacks);
}

int main(int ac, char **av)
{
	t_stack	*stacks;
	(void)av;

	stacks = create_stacks(ac);
	printf("Hello world!\n");
	return (0);
}
