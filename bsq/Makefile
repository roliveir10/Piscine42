# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 12:49:55 by roolivei          #+#    #+#              #
#    Updated: 2021/07/21 15:25:28 by roolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror
LDFLAGS = 

INC_DIR = includes

SRCS = srcs/main.c		\
	   srcs/lib.c		\
	   srcs/io.c		\
	   srcs/parser.c	\
	   srcs/fill_tab.c	\
	   srcs/lib2.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
