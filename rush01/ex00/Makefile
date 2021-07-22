# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 13:14:33 by roolivei          #+#    #+#              #
#    Updated: 2021/07/10 21:03:44 by roolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-01

CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror

INC_DIR =

SRCS = alloc.c			\
	   backtracking.c	\
	   lib2.c			\
	   lib.c			\
	   limit.c			\
	   main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
