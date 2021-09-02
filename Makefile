# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 20:40:48 by sdummett          #+#    #+#              #
#    Updated: 2021/09/02 20:11:08 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC			= clang -g3 #-fsanitize=address
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
			  utils/ft_atoi.c \
			  utils/is_sorted.c \
			  utils/clean_exit.c \
			  stacks/print_stacks.c \
			  stacks/stacks_utils.c \
			  algorithm/done/ugly_algorithm.c \
			  algorithm/done_2/sort_stack_a_into_another_tab.c \
			  algorithm/done_2/get_median.c \
			  algorithm/done_2/split_until_median.c \
			  algorithm/done_2/get_extreme_numbers.c \
			  algorithm/done_2/stick_extreme_numbers.c \
			  algorithm/done_2/get_index_max.c \
			  algorithm/done_2/get_index_min.c \
			  algorithm/done_2/is_pseudo_sorted.c \
			  algorithm/done_2/how_to_move_pseudo_sorted.c \
			  algorithm/done_2/move_min_to_top_with_ra.c \
			  algorithm/done_2/move_min_to_top_with_rra.c \
			  algorithm/done_2/find_biggest_number.c  \
			  algorithm/done_2/sort_curr_biggest_number.c \
			  algorithm/done_2/get_number_index.c \
			  algorithm/done_2/sort_stack_a.c \
			  algorithm/move_stack_a_into_b.c \
			  algorithm/count_moves.c \
			  algorithm/print_moves.c
INC			= -Iincludes
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
