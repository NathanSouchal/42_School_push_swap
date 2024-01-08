# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 09:38:53 by nsouchal          #+#    #+#              #
#    Updated: 2024/01/05 09:27:55 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		$(CC) $(FLAGS) $(OBJS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./printf fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
