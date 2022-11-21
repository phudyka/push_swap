# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:36:19 by phudyka           #+#    #+#              #
#    Updated: 2022/11/21 10:38:38 by phudyka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra 
SRC  =  main.c

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