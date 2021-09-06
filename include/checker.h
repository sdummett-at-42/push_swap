/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 16:24:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** Temporary # include <stdio.h>
*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int				*a;
	int				*b;
	unsigned int	nb_elem_a;
	unsigned int	nb_elem_b;
}	t_stacks;

int		ft_atoi_on_steroid(const char *str, unsigned char *overflow);
void	clean_exit(t_stacks *stacks, int exit_status);
int		is_number(char *arg);
int		has_duplicates(t_stacks *stacks);

#endif