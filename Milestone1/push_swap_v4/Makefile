# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 11:01:59 by rirazafi          #+#    #+#              #
#    Updated: 2026/03/12 09:45:34 by rirazafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c \
		main_parser.c \
		algo_selector.c \
		move_cheapest.c \
		get_fields_stack.c \
		ops_push.c \
		ops_swap.c \
		ops_rotate.c \
		ops_rrotate.c \
		set_fields_stack_1.c \
		set_fields_stack_2.c \
		sort_insertion.c \
		sort_small.c \
		sort_radix_lsd.c \
		sort_chunk.c \
		sort_chunk_utils.c \
		bench.c \
		bench_stderr.c \
		stderr_print.c \
		init_stack.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
