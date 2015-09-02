# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:18:54 by tsilberm          #+#    #+#              #
#    Updated: 2015/07/21 22:25:44 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = do-op

SRC = print.c main.c error.c operation.c ft_atoi.c
OBJ = print.o main.o error.o operation.o ft_atoi.o

HEADER = header.h

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f print.o main.o error.o operation.o ft_atoi.o header.h.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean 
	all
