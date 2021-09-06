/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 00:06:20 by sdummett         ###   ########.fr       */
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

typedef struct s_instruc
{
	char				*content;
	struct s_instruc	*next;
}	t_instruc;

int			ft_atoi_on_steroid(const char *str, unsigned char *overflow);
void		clean_exit(t_stacks *stacks, int exit_status);
int			is_number(char *arg);
int			has_duplicates(t_stacks *stacks);

/*
** Stacks management
*/
int			init_stacks(t_stacks *stacks, int ac, char **av);
t_stacks	*create_stacks(int ac);

/*
** get_next_line
*/
int			get_next_line(int fd, char **line);

int			ft_memcmp(const void *b1, const void *b2, size_t len);
int			ft_strlen(char *str);

/*
** t_instruc struct | Instructions
*/
t_instruc	*lstnew(char *line);
void		lstadd_back(t_instruc **alst, t_instruc *new);
void		lst_clear(t_instruc **lst);
t_instruc	*get_instructions(void);

/*
** Debug
*/
void		print_stacks(t_stacks *stacks);

#endif