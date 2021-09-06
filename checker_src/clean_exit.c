/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:22:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 16:22:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stacks *stacks, int exit_status)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	exit(exit_status);
}
