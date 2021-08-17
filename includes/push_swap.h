/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:16:12 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/17 23:29:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h> // <- to delete
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	unsigned int	nb_elem_total;
	unsigned int	nb_elem_a;
	unsigned int	nb_elem_b;
}	t_stacks;

int	ft_atoi(const char *str);
void	init_stacks(t_stacks *stacks, char **av);
t_stacks	*create_stacks(int ac);
void	print_stacks(t_stacks *stacks);

/*
** Instructions
*/

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_a_b(t_stacks *stacks);

#endif

