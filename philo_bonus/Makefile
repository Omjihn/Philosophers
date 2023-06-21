# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 15:47:42 by gbricot           #+#    #+#              #
#    Updated: 2023/06/21 18:05:20 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

LOGO = "\n  _____  _     _ _                       _                   \n |  __ \| |   (_) |                     | |                  \n | |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___ \n |  ___/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|\n | |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \\n |_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/\n                                  | |                        \n                                  |_|         bonus                  \n"

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c \
	src/ft_philosopher.c \
	src/ft_init.c \
	src/ft_clear.c \
	src/ft_atoi.c \
	src/ft_calloc.c


OBJ = $(SRC:.c=.o)

$(NAME): draw $(OBJ)
	$(CC) -pthread $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

draw:
	@echo $(LOGO)

re: fclean all
