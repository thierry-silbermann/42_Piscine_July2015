# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/26 23:40:41 by tsilberm          #+#    #+#              #
#    Updated: 2015/07/30 17:20:06 by jguthert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = bsq

SRCS = print.c main.c best_sqr.c ft_read_from_stdin.c ft_verif_map.c\
		 linked_list.c print_solution.c search_solution.c
BIN = print.o main.o best_sqr.o ft_read_from_stdin.o ft_verif_map.o\
		 linked_list.o print_solution.o search_solution.o

LIB = header.h

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Werror -Wextra $(SRCS) -I $(LIB)
	gcc -o $(NAME) $(BIN)

clean :
	/bin/rm -f $(BIN)

fclean : clean 
	/bin/rm -f $(NAME)

re : fclean all