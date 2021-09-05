/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:16:12 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/05 13:21:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** Temporary # include <stdio.h>
*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_move_2
{
	int	ra;
	int	rra;
}	t_move_2;

/*
** The purpose of this structure is to know which instruction to do
** while sticking the extreme values of stack A
*/
typedef struct s_move
{
	int	min_rra;
	int	min_ra;
	int	max_rra;
	int	max_ra;
}	t_move;

/*
** Structure to get the numbers sorted
*/
typedef struct s_sorted
{
	int				*list;
	unsigned int	total;
}	t_sorted;

/*
** Structure for holding the two stacks
*/

/*
**
** => long int **best_moves
**	   INDEX	                [0]                           [1]
** | index_elem_b | index of the next elem (elem_a) | total numbers of ops |
**
**/
typedef struct s_stacks
{
	int				*a;
	int				*b;
	unsigned int	nb_elem_total;
	unsigned int	nb_elem_a;
	unsigned int	nb_elem_b;
	long int		*moves_a;
	long int		*moves_b;
	long int		**best_moves;
	t_sorted		*sorted;
}	t_stacks;

/*
** Stacks funcs
*/
void			print_stacks(t_stacks *stacks);
int				init_stacks(t_stacks *stacks, int ac, char **av);
t_stacks		*create_stacks(int ac);
void			print_stacks(t_stacks *stacks);

/*
** Instructions funcs
*/
void			swap_a(t_stacks *stacks);
void			swap_b(t_stacks *stacks);
void			swap_a_b(t_stacks *stacks);
void			push_a(t_stacks *stacks);
void			push_b(t_stacks *stacks);
void			rotate_a(t_stacks *stacks);
void			rotate_b(t_stacks *stacks);
void			rotate_a_b(t_stacks *stacks);
void			reverse_rotate_a(t_stacks *stacks);
void			reverse_rotate_b(t_stacks *stacks);
void			reverse_rotate_a_b(t_stacks *stacks);

/*
** Utils funcs
*/
int				ft_atoi_on_steroid(const char *str, unsigned char *overflow);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *b, size_t len);
int				is_number(char *arg);
int				has_duplicates(t_stacks *stacks);
char			**ft_split(char const *s, char c);
int				is_sorted(t_stacks *stacks);
void			clean_exit(t_stacks *stacks);

/*
** Debug funcs
*/
void			print_sorted(t_sorted *sorted);

/*
** Algorithm
*/
t_sorted		*sort_stack_a_into_another_tab(t_stacks *stacks);
int				get_median(t_sorted *sorted);
void			split_until_median(t_stacks *stacks);
int				get_min_number(t_stacks *stacks);
int				get_max_number(t_stacks *stacks);
unsigned int	get_index_min(t_stacks *stacks);
unsigned int	get_index_max(t_stacks *stacks);
int				is_pseudo_sorted(t_stacks *stacks);
void			move_min_to_top_with_ra(t_stacks *stacks);
void			move_min_to_top_with_rra(t_stacks *stacks);
void			how_to_move_pseudo_sorted(t_stacks *stacks, t_move_2 *move_2);
void			move_stack_a_int_b(t_stacks *stacks);
void			count_moves(t_stacks *stacks);
void			print_moves(t_stacks *stacks);
unsigned int	get_next_value_index(t_stacks *stacks, int elem_to_sort);
void			get_best_moves(t_stacks *stacks);
void			print_best_moves(t_stacks *stacks);
long int		get_index_best_moves(t_stacks *stacks);
void			move_elem(t_stacks *stacks);
void			optimized_sort(t_stacks *stacks);
void			three_elements_sort(t_stacks *stacks);
void			five_elements_sort(t_stacks *stacks);

#endif
