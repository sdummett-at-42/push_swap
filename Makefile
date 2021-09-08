# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 20:40:48 by sdummett          #+#    #+#              #
#    Updated: 2021/09/08 16:18:12 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

DEFAULT		= "\e[39m"
GREEN		= "\e[32m"
RED			= "\e[31m"
MAGENTA		= "\e[35m"
CC			= clang #-g3 -fsanitize=address
CFLAGS		= -Wall -Werror -Wextra
NAME		= push_swap
NAME_BONUS	= checker
SRC			= src_push_swap/push_swap.c \
			  src_push_swap/instructions/swap_a.c \
			  src_push_swap/instructions/swap_b.c \
			  src_push_swap/instructions/swap_a_b.c \
			  src_push_swap/instructions/push_a.c \
			  src_push_swap/instructions/push_b.c \
			  src_push_swap/instructions/rotate_a.c \
			  src_push_swap/instructions/rotate_b.c \
			  src_push_swap/instructions/rotate_a_b.c \
			  src_push_swap/instructions/reverse_rotate_a.c \
			  src_push_swap/instructions/reverse_rotate_b.c \
			  src_push_swap/instructions/reverse_rotate_a_b.c \
			  src_push_swap/boolean/is_number.c \
			  src_push_swap/boolean/has_duplicates.c \
			  src_push_swap/utils/ft_atoi_on_steroid.c \
			  src_push_swap/boolean/is_sorted.c \
			  src_push_swap/utils/clean_exit.c \
			  src_push_swap/stacks/stacks_utils.c \
			  src_push_swap/algorithm/sort_stack_a_into_another_tab.c \
			  src_push_swap/algorithm/get_median.c \
			  src_push_swap/algorithm/split_until_median.c \
			  src_push_swap/algorithm/get_extreme_numbers.c \
			  src_push_swap/algorithm/get_extreme_index.c \
			  src_push_swap/boolean/is_circular_sorted.c \
			  src_push_swap/algorithm/how_to_sort_circular_sorted_stack.c \
			  src_push_swap/algorithm/move_min_to_top.c \
			  src_push_swap/algorithm/move_stack_a_into_b.c \
			  src_push_swap/algorithm/count_moves.c \
			  src_push_swap/algorithm/get_next_value_index.c\
			  src_push_swap/algorithm/get_best_moves.c \
			  src_push_swap/algorithm/get_index_best_move.c \
			  src_push_swap/algorithm/move_elem.c \
			  src_push_swap/algorithm/circular_sort.c \
			  src_push_swap/debug/print_sorted.c \
			  src_push_swap/debug/print_moves.c \
			  src_push_swap/debug/print_best_moves.c \
			  src_push_swap/debug/print_stacks.c \
			  src_push_swap/algorithm/three_elements_sort.c \
			  src_push_swap/algorithm/five_elements_sort.c \
			  src_push_swap/algorithm/move_opposite_way.c \
			  src_push_swap/algorithm/move_same_way_bot.c \
			  src_push_swap/algorithm/move_same_way_top.c \
			  src_push_swap/check_errors.c \
			  src_push_swap/boolean/args_are_numbers.c
			  
INC			= -Iinclude
includes	= $(wildcard includes/*.h)
OBJ			= $(SRC:.c=.o)
SRCBONUS	= checker_src/checker.c \
				checker_src/ft_atoi_on_steroid.c \
				checker_src/clean_exit.c \
				checker_src/boolean/is_number.c \
				checker_src/boolean/has_duplicates.c \
				checker_src/debug/print_stacks.c \
				checker_src/instructions/swap_a.c \
				checker_src/instructions/swap_b.c \
				checker_src/instructions/swap_a_b.c \
				checker_src/instructions/push_a.c \
				checker_src/instructions/push_b.c \
				checker_src/instructions/rotate_a.c \
				checker_src/instructions/rotate_b.c \
				checker_src/instructions/rotate_a_b.c \
				checker_src/instructions/reverse_rotate_a.c \
				checker_src/instructions/reverse_rotate_b.c \
				checker_src/instructions/reverse_rotate_a_b.c \
				checker_src/get_next_line/get_next_line_utils.c \
				checker_src/get_next_line/get_next_line.c \
				checker_src/stacks_utils/stacks_management.c \
				checker_src/get_instructions.c \
				checker_src/t_instruc_utils/t_instruc_utils.c \
				checker_src/ft_memcmp.c \
				checker_src/ft_strlen.c \
				checker_src/instructions_check/is_pa.c \
				checker_src/instructions_check/is_pb.c \
				checker_src/instructions_check/is_ra.c \
				checker_src/instructions_check/is_rb.c \
				checker_src/instructions_check/is_rr.c \
				checker_src/instructions_check/is_rra.c \
				checker_src/instructions_check/is_rrb.c \
				checker_src/instructions_check/is_rrr.c \
				checker_src/instructions_check/is_sa.c \
				checker_src/instructions_check/is_sb.c \
				checker_src/instructions_check/is_ss.c \
				checker_src/boolean/is_sorted.c \
				checker_src/do_instructions.c \
				checker_src/check_errors/check_errors.c \
				checker_src/boolean/args_are_numbers.c

OBJBONUS	=$(SRCBONUS:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

enable_colors:
	echo -e $(GREEN)

disable_colors:
	echO -e $(DEFAULT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME_BONUS)

%.o: %.c $(includes)
	$(CC) $(INC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f $(OBJBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all 
