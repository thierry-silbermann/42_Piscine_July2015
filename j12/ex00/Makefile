# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/23 18:17:28 by tsilberm          #+#    #+#              #
#    Updated: 2015/07/23 19:02:02 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_display_file

SRC = print.c main.c
OBJ = print.o main.o

HEADER = header.h

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	$(CC) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f print.o main.o

fclean: clean
	/bin/rm -f $(NAME)
