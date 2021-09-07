/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:52:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 02:10:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stacks *stacks)
{
	int				tmp;
	unsigned int	i;

	if (stacks->nb_elem_a < 2)
		return ;
	i = stacks->nb_elem_a - 1;
	tmp = stacks->a[i];
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[i] = tmp;
}
