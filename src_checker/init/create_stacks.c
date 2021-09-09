/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:23:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 14:23:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
