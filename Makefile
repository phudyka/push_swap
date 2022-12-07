# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:36:19 by phudyka           #+#    #+#              #
#    Updated: 2022/12/07 11:33:17 by phudyka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra 
SRC  =  printstruct.c main.c check.c utils.c stack.c mini.c maxi.c presort.c target.c move.c reverse.c swap.c rotate.c push.c end.c

OBJ = $(patsubst %.c,%.o,$(SRC))
INCLUDES = push_swap.h
DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

all : $(NAME)

lib : 
	@make -C $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o : %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C $(DIR_LIB) clean

fclean : clean
	rm -f $(NAME)
	make -C $(DIR_LIB) fclean
	
re : fclean all

.PHONY : all clean fclean re