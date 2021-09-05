# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 20:40:48 by sdummett          #+#    #+#              #
#    Updated: 2021/09/05 13:22:07 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC			= clang #-g3 -fsanitize=address
CFLAGS		= -Wall -Werror -Wextra
NAME		= push_swap
SRC			= push_swap.c \
			  instructions/swap_a.c \
			  instructions/swap_b.c \
			  instructions/swap_a_b.c \
			  instructions/push_a.c \
			  instructions/push_b.c \
			  instructions/rotate_a.c \
			  instructions/rotate_b.c \
			  instructions/rotate_a_b.c \
			  instructions/reverse_rotate_a.c \
			  instructions/reverse_rotate_b.c \
			  instructions/reverse_rotate_a_b.c \
			  utils/is_number.c \
			  utils/has_duplicates.c \
			  utils/ft_atoi_on_steroid.c \
			  utils/is_sorted.c \
			  utils/clean_exit.c \
			  stacks/stacks_utils.c \
			  algorithm/sort_stack_a_into_another_tab.c \
			  algorithm/get_median.c \
			  algorithm/split_until_median.c \
			  algorithm/get_extreme_numbers.c \
			  algorithm/get_index_max.c \
			  algorithm/get_index_min.c \
			  algorithm/is_pseudo_sorted.c \
			  algorithm/how_to_move_pseudo_sorted.c \
			  algorithm/move_min_to_top_with_ra.c \
			  algorithm/move_min_to_top_with_rra.c \
			  algorithm/move_stack_a_into_b.c \
			  algorithm/count_moves.c \
			  algorithm/get_next_value_index.c\
			  algorithm/get_best_moves.c \
			  algorithm/get_index_best_move.c \
			  algorithm/move_elem.c \
			  algorithm/optimized_sort.c \
			  debug/print_sorted.c \
			  debug/print_moves.c \
			  debug/print_best_moves.c \
			  debug/print_stacks.c \
			  algorithm/three_elements_sort.c \
			  algorithm/five_elements_sort.c
			  
INC			= -Iinclude
includes	= $(wildcard includes/*.h)
OBJ			= $(SRC:.c=.o)
SRCBONUS	= NEANT

OBJBONUS	=$(SRCBONUS:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME)

%.o: %.c $(includes)
	$(CC) $(INC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all 
