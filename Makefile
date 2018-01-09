# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparabos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 12:54:29 by aparabos          #+#    #+#              #
#    Updated: 2017/12/10 10:51:43 by aparabos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
NAME = test_gnl
SRCS = get_next_line.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
		make -C libft/
		clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
		clang  -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
