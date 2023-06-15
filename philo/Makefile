# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 14:50:07 by gbricot           #+#    #+#              #
#    Updated: 2023/06/15 17:32:31 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

LOGO = "  _____   _      _  _                            _                 \n |  __ \ | |    (_)| |                          | |                \n | |__) || |__   _ | |  ___   ___   ___   _ __  | |__    ___  _ __ \n |  ___/ | '_ \ | || | / _ \ / __| / _ \ | '_ \ | '_ \  / _ \| '__|\n | |     | | | || || || (_) |\__ \| (_) || |_) || | | ||  __/| |   \n |_|     |_| |_||_||_| \___/ |___/ \___/ | .__/ |_| |_| \___||_|                                                         | |                       \n                                         |_|                       "

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c \
	src/ft_life_cycle.c \
	src/ft_life_cycle_extend.c \
	src/ft_init.c \
	src/ft_clear.c \
	src/ft_calloc.c \
	src/ft_atoi.c

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
