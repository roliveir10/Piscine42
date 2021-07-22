# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 13:14:33 by roolivei          #+#    #+#              #
#    Updated: 2021/07/18 18:36:58 by roolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

INC_DIR = includes

SRCS = srcs/main.c					\
	   srcs/list.c					\
	   srcs/ft_io.c					\
	   srcs/ft_display.c			\
	   srcs/ft_display_func.c		\
	   srcs/ft_error.c				\
	   srcs/ft_build_lst.c			\
	   srcs/ft_alloc.c				\
	   srcs/ft_extra.c				\
	   srcs/language.c				\
	   lib/ft_filedup.c				\
	   lib/ft_bzero.c				\
	   lib/ft_strncmp.c				\
	   lib/ft_strslen.c				\
	   lib/ft_split.c				\
	   lib/ft_strcat.c				\
	   lib/ft_strcpy.c				\
	   lib/ft_strjoinf.c			\
	   lib/ft_del_words_tables.c	\
	   lib/ft_strlen.c				\
	   lib/ft_putstr.c				\
	   lib/ft_str_is_printable.c	\
	   lib/ft_strndup.c				\
	   lib/ft_print_words_tables.c	\
	   lib/ft_nbrlen.c				\
	   lib/ft_strchr.c				\
	   lib/ft_strdup.c				\
	   lib/ft_strtrim.c				\
	   lib/ft_strncpy.c				\
	   lib/ft_is_space.c			\
	   lib/ft_strlcpy.c				\
	   lib/ft_atoi.c				\
	   lib/ft_isdigit.c				\
	   lib/ft_str_is_numeric.c		\
	   lib/ft_str_to_n_integer.c	\
	   lib/ft_ncmp.c				\
	   lib/ft_strdel.c				\
	   lib/ft_strcmp.c				\
	   lib/ft_strjoin.c

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
