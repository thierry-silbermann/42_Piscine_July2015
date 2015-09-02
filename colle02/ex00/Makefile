# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/26 23:40:41 by tsilberm          #+#    #+#              #
#    Updated: 2015/07/26 23:50:02 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    =   colle-2

SRCS    =   print.c  read.c check.c check_2.c ass.c 

LIB     =   includes/header.h

all     :   $(NAME)

$(NAME) :
	gcc -o $(NAME) -Wall -Werror -Wextra $(SRCS) -I $(LIB)

fclean: 
	/bin/rm -f $(NAME)
