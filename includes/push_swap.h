/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:16:12 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/28 21:48:58 by sdummett         ###   ########.fr       */
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

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
** Stacks funcs
*/

void		print_stacks(t_stacks *stacks);
int			ft_atoi(const char *str, unsigned char *overflow);
int			init_stacks(t_stacks *stacks,int ac, char **av);
t_stacks	*create_stacks(int ac);
void		print_stacks(t_stacks *stacks);

/*
** Instructions funcs
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
** Utils funcs
*/

void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *b, size_t len);
int			is_number(char *arg);
int			has_duplicates(t_stacks *stacks);
char		**ft_split(char const *s, char c);
int			is_sorted(t_stacks *stacks);
void		clean_exit(t_stacks *stacks);

/*
** Algorithm
*/

void		ugly_sort(t_stacks *stacks);

#endif
