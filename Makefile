# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 13:16:25 by axelgerv          #+#    #+#              #
#    Updated: 2019/01/10 11:00:27 by axelgerv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OK_COLOR = \033[32m
NO_COLOR = \033[m

OK = $(OK_COLOR)OK$(NO_COLOR)

NAME = fillit

IDIR = -Iincludes/ -Ilibft/includes

SRC =  main.c \
	   generator_map.c \
	   check_error.c \
	   read_fd.c \
	   storage.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/ fclean && make -C libft/
	@$(CC) -o $(NAME) $(IDIR) $(OBJ) libft/libft.a
	@echo "[fillit] | Compilation						$(OK)"

%.o: %.c
	@$(CC) $(CFLAGS) $(IDIR) -o $@ -c $<

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "[fillit] | clean						$(OK)"

fclean : clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "[fillit] | fclean						$(OK)"

re : fclean all
