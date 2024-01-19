# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 09:38:53 by nsouchal          #+#    #+#              #
#    Updated: 2024/01/19 14:16:59 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

SRCS_BONUS = ./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/main.c \
			./bonus/push_bonus.c ./bonus/reverse_rotate_bonus.c ./bonus/rotate_bonus.c \
			 ./bonus/swap_bonus.c algo_utils_1.c initialize.c lst_utils.c push.c rotate.c \
			 reverse_rotate.c swap.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = push_swap

NAME_BONUS = checker

FLAGS = -Wall -Werror -Wextra

CC = cc

HEADERFILE = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADERFILE)
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		$(CC) $(FLAGS) $(OBJS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

bonus : $(OBJS_BONUS)
		$(CC) $(FLAGS) $(OBJS_BONUS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME_BONUS)

clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./printf fclean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
