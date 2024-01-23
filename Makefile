# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 09:38:53 by nsouchal          #+#    #+#              #
#    Updated: 2024/01/22 15:55:13 by nsouchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algo_utils_1.c algo_utils.c calculate_cost.c initialize.c lst_utils.c main.c \
		moves_to_a.c moves_to_b.c push.c reverse_rotate.c rotate.c sortings.c swap.c

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

HEADERFILE_BONUS = ./bonus/checker.h ./bonus/get_next_line.h

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(HEADERFILE)
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		$(CC) $(FLAGS) $(OBJS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(HEADERFILE) $(HEADERFILE_BONUS)
				$(CC) $(FLAGS) $(OBJS_BONUS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME_BONUS)

.PHONY: bonus
bonus : $(NAME_BONUS)

.PHONY: clean
clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./printf fclean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)


.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

.PHONY: re
re: fclean
	$(MAKE) all
