# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 14:50:07 by gbricot           #+#    #+#              #
#    Updated: 2023/06/12 18:36:32 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

//CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c \
	src/ft_init.c \
	libft/ft_calloc.c \
	libft/ft_atoi.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) -pthread $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
