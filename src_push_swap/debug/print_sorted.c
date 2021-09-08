/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:44:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/04 16:45:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Debug function
*/
void	print_sorted(t_sorted *sorted)
{
	unsigned int	i;
	i = 0;
	while (i < sorted->total)
	{
		printf("[%d]", sorted->list[i]);
		i++;
	}
	printf("\n");
}
