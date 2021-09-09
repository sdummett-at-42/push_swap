# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 20:40:48 by sdummett          #+#    #+#              #
#    Updated: 2021/09/09 19:56:26 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

MAG	= \033[0;35m
WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
GRN	= \033[0;32m
RM	= rm -f
CC			= 		clang #-g3 -fsanitize=address
CFLAGS		= 		-Wall -Werror -Wextra
NAME		= 		push_swap
NAME_BONUS	= 		checker
INC			= 		-Iinclude
MANDATORY_PATH =	src_push_swap/
INSTRUCTIONS_PATH = instructions/
BOOLEAN_PATH = 		boolean/
UTILS_PATH = 		utils/
ALGORITHM_PATH = 	algorithm/
DEBUG_PATH = 		debug/
INIT_PATH = 		init/
BONUS_PATH =		src_checker/
GET_NEXT_LINE = 	get_next_line/
INSTRUCTIONS_CHECK_PATH = instructions_check/
SRC_PREFIXED = $(addprefix $(INSTRUCTIONS_PATH), swap_a.c swap_b.c swap_a_b.c \
				push_a.c push_b.c rotate_a.c rotate_b.c rotate_a_b.c reverse_rotate_a.c \
				reverse_rotate_b.c reverse_rotate_a_b.c) \
				$(addprefix $(BOOLEAN_PATH), is_number.c has_duplicates.c \
				is_sorted.c is_circular_sorted.c args_are_numbers.c) \
				$(addprefix $(UTILS_PATH), ft_atoi_on_steroid.c clean_exit.c) \
				$(addprefix $(ALGORITHM_PATH), sort_stack_a_into_another_tab.c \
				get_median.c split_until_median.c get_extreme_numbers.c \
				get_extreme_index.c how_to_sort_circular_sorted_stack.c move_min_to_top.c \
				move_stack_a_into_b.c count_moves.c get_next_value_index.c \
				get_best_moves.c get_index_best_move.c move_elem.c circular_sort.c \
				three_elements_sort.c five_elements_sort.c move_opposite_way.c \
				move_same_way_bot.c move_same_way_top.c) \
				$(addprefix $(DEBUG_PATH), print_moves.c print_best_moves.c print_stacks.c) \
				$(addprefix $(INIT_PATH), check_errors.c init_stacks.c create_stacks.c)
SRC			= $(addprefix $(MANDATORY_PATH), push_swap.c $(SRC_PREFIXED))
OBJ			= $(SRC:.c=.o)
includes	= $(wildcard include/*.h)
SRC_BONUS_PREFIXED = $(addprefix $(UTILS_PATH), ft_atoi_on_steroid.c clean_exit.c \
					ft_memcmp.c ft_strlen.c lst_new.c lstadd_back.c lst_clear.c) \
					$(addprefix $(BOOLEAN_PATH), is_number.c has_duplicates.c \
					is_sorted.c args_are_numbers.c are_valid_instructions.c) \
					$(addprefix $(INSTRUCTIONS_PATH), swap_a.c swap_b.c \
					swap_a_b.c push_a.c push_b.c rotate_a.c rotate_b.c \
					rotate_a_b.c reverse_rotate_a.c reverse_rotate_b.c \
					reverse_rotate_a_b.c get_instructions.c do_instructions.c) \
					$(addprefix $(GET_NEXT_LINE), get_next_line_utils.c get_next_line.c) \
					$(addprefix $(INSTRUCTIONS_CHECK_PATH), is_pa.c is_pb.c is_ra.c \
					is_rb.c is_rr.c is_rra.c is_rrb.c is_rrr.c is_sa.c is_sb.c is_ss.c) \
					$(addprefix $(INIT_PATH), check_errors.c create_stacks.c init_stacks.c) \
					$(addprefix $(DEBUG_PATH), print_stacks.c )
SRCBONUS	= $(addprefix $(BONUS_PATH), checker.c $(SRC_BONUS_PREFIXED))
OBJBONUS	=$(SRCBONUS:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME) $(NAME_BONUS)
	@printf "$(MAG)                  _                                $(MAG)\n"
	@printf "$(MAG)                 | |                               $(MAG)\n"
	@printf "$(MAG)  _ __  _   _ ___| |__    _____      ____ _ _ __   $(MAG)\n"
	@printf "$(MAG) | '_ \| | | / __| '_ \  / __\ \ /\ / / _\` | '_ \  $(MAG)\n"
	@printf "$(MAG) | |_) | |_| \__ \ | | | \__ \\\ V  V / (_| | |_) | $(MAG)\n"
	@printf "$(MAG) | .__/ \__,_|___/_| |_| |___/ \_/\_/ \__,_| .__/  $(MAG)\n"
	@printf "$(MAG) | |                 ______                | |     $(MAG)\n"
	@printf "$(MAG) |_|                |______|               |_|     $(MAG)\n"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

$(NAME_BONUS): $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME_BONUS)
	@printf "$(WHT)[$(GRN)$(NAME_BONUS) COMPILED$(WHT)]\n"

bonus: $(NAME_BONUS)

%.o: %.c $(includes)
	$(CC) $(INC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJBONUS)
	@printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re: fclean all bonus

