# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 11:45:29 by salaoui           #+#    #+#              #
#    Updated: 2024/06/09 13:20:01 by salaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c push_swap_utils.c push_swap_utils_2.c sort_small_stack.c sort_stack.c to_stack_b_insta.c sort_stack_again.c to_stack_a_instra.c check_sorted_or_double.c free_memory.c
SRCB = My_checker.c push_swap_utils_bonus.c check_sorted_or_double_bonus.c free_memory.c get_next_line.c get_next_line_utils.c instractions_bonus.c more_instra_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAMEB = checker
# LIBRARY = libftprintf.a

SRC_o := $(SRC:.c=.o)
SRCB_o := $(SRCB:.c=.o)

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(SRC_o)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_o)

$(NAMEB): $(SRCB_o)
	$(CC) $(CFLAGS) -o $(NAMEB) $(SRCB_o)

clean:
	rm -f $(SRC_o)
	rm -f $(SRCB_o)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEB)

re: fclean all bonus

.SECONDARY: $(SRC_o) $(SRCB_o)