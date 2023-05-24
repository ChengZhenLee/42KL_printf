# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenglee <chenglee@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 16:07:47 by chenglee          #+#    #+#              #
#    Updated: 2023/05/24 16:09:23 by chenglee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c numbers.c strings.c
OBJ = ${SRC:%.c=%.o}
HEAD = ft_printf.h
NAME = libftprintf.a

CC = cc
AR = ar
CFLAGS = -c -Wall -Werror -Wextra
LIBFLAGS = -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(LIBFLAGS) $(NAME) $(OBJ)

$(OBJ): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re