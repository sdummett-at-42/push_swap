# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 20:40:48 by sdummett          #+#    #+#              #
#    Updated: 2021/09/09 12:23:27 by sdummett         ###   ########.fr        #
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
			  src_push_swap/init/check_errors.c \
			  src_push_swap/boolean/args_are_numbers.c \
			  src_push_swap/init/init_stacks.c \
			  src_push_swap/init/create_stacks.c
			  
INC			= -Iinclude
includes	= $(wildcard includes/*.h)
OBJ			= $(SRC:.c=.o)
SRCBONUS	= src_checker/checker.c \
				src_checker/ft_atoi_on_steroid.c \
				src_checker/clean_exit.c \
				src_checker/boolean/is_number.c \
				src_checker/boolean/has_duplicates.c \
				src_checker/debug/print_stacks.c \
				src_checker/instructions/swap_a.c \
				src_checker/instructions/swap_b.c \
				src_checker/instructions/swap_a_b.c \
				src_checker/instructions/push_a.c \
				src_checker/instructions/push_b.c \
				src_checker/instructions/rotate_a.c \
				src_checker/instructions/rotate_b.c \
				src_checker/instructions/rotate_a_b.c \
				src_checker/instructions/reverse_rotate_a.c \
				src_checker/instructions/reverse_rotate_b.c \
				src_checker/instructions/reverse_rotate_a_b.c \
				src_checker/get_next_line/get_next_line_utils.c \
				src_checker/get_next_line/get_next_line.c \
				src_checker/stacks_utils/stacks_management.c \
				src_checker/get_instructions.c \
				src_checker/t_instruc_utils/t_instruc_utils.c \
				src_checker/ft_memcmp.c \
				src_checker/ft_strlen.c \
				src_checker/instructions_check/is_pa.c \
				src_checker/instructions_check/is_pb.c \
				src_checker/instructions_check/is_ra.c \
				src_checker/instructions_check/is_rb.c \
				src_checker/instructions_check/is_rr.c \
				src_checker/instructions_check/is_rra.c \
				src_checker/instructions_check/is_rrb.c \
				src_checker/instructions_check/is_rrr.c \
				src_checker/instructions_check/is_sa.c \
				src_checker/instructions_check/is_sb.c \
				src_checker/instructions_check/is_ss.c \
				src_checker/boolean/is_sorted.c \
				src_checker/do_instructions.c \
				src_checker/check_errors/check_errors.c \
				src_checker/boolean/args_are_numbers.c

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
