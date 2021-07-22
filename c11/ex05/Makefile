# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 13:14:33 by roolivei          #+#    #+#              #
#    Updated: 2021/07/12 22:07:25 by roolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_doop.c		\
	   ft_operator.c	\
	   lib.c

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

.PHONY: all clean fclean
