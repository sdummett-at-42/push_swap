/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 01:39:40 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define SA 255
# define SB 254
# define SS 253
# define PA 252
# define PB 251
# define RA 250
# define RB 249
# define RR 248
# define RRA 247
# define RRB 246
# define RRR 245
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
	short				instruction;
	struct s_instruc	*next;
}	t_instruc;

int			ft_atoi_on_steroid(const char *str, unsigned char *overflow);
void		clean_exit(t_stacks *stacks, int exit_status);
int			is_number(char *arg);
int			has_duplicates(t_stacks *stacks);
int			is_sorted(t_stacks *stacks);

/*
** Stacks management
*/
int			init_stacks(t_stacks *stacks, int ac, char **av);
t_stacks	*create_stacks(int ac);

/*
** Stack instructions
*/
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_a_b(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_a_b(t_stacks *stacks);
void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_a_b(t_stacks *stacks);

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
** Instructions check
*/
void		is_sa(t_instruc *lst, int *res);
void		is_sb(t_instruc *lst, int *res);
void		is_ss(t_instruc *lst, int *res);
void		is_pa(t_instruc *lst, int *res);
void		is_pb(t_instruc *lst, int *res);
void		is_ra(t_instruc *lst, int *res);
void		is_rb(t_instruc *lst, int *res);
void		is_rr(t_instruc *lst, int *res);
void		is_rra(t_instruc *lst, int *res);
void		is_rrb(t_instruc *lst, int *res);
void		is_rrr(t_instruc *lst, int *res);

/*
** Debug
*/
void		print_stacks(t_stacks *stacks);

#endif