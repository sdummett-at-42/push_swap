# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 20:40:48 by sdummett          #+#    #+#              #
#    Updated: 2021/08/20 18:36:35 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC			= clang
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
			  lst/ft_lstnew.c \
			  lst/ft_lstadd_back.c \
			  lst/ft_lstclear.c \
			  utils/ft_calloc.c \
			  utils/ft_bzero.c \
			  utils/is_number.c \
			  utils/no_num_dup.c \
			  utils/ft_split.c \
			  utils/ft_atoi.c \
			  stacks/print_stacks.c \
			  stacks/stacks_utils.c	  
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
