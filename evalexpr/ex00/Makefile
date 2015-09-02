# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/26 20:36:24 by tsilberm          #+#    #+#              #
#    Updated: 2015/07/26 20:39:06 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = eval_expr

SRC = print.c main.c string_manip.c str_int.c calcul.c lol.c

HEADER = header.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f main.o

fclean: clean
	/bin/rm -f $(NAME)
