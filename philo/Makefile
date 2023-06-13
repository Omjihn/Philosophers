# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 14:50:07 by gbricot           #+#    #+#              #
#    Updated: 2023/06/13 17:20:46 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

//CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c \
	src/ft_life_cycle.c \
	src/ft_init.c \
	src/ft_calloc.c \
	src/ft_atoi.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) -pthread $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
