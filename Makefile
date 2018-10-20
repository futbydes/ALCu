# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vludan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 17:25:13 by vludan            #+#    #+#              #
#    Updated: 2018/10/19 17:26:22 by vludan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c alum1.c
OBJ = $(SRC:.c=.o)
INCLUDES = alum1.h
NAME = alum1
CFLAGS = -Wall -Werror -Wextra
CC = gcc 
DIR = libft
DIR_PF = libft/ft_printf

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DIR)
	make -C $(DIR_PF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. $(DIR)/libft.a $(DIR_PF)/libftprintf.a

clean:
	make clean -C $(DIR)
	make clean -C $(DIR_PF)
	rm -f $(OBJ)

fclean:
	make fclean -C $(DIR)
	make fclean -C $(DIR_PF)
	rm -f $(NAME) $(OBJ)

re: fclean all
