# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 13:14:33 by roolivei          #+#    #+#              #
#    Updated: 2021/07/13 21:45:19 by roolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

INC_DIR =

SRCS = ft_hexdump.c		\
	   lib.c			\
	   lib2.c			\
	   ft_display.c		\
	   ft_linehandler.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -I$(INC_DIR)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
