# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manufern <manufern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 18:23:23 by manufern          #+#    #+#              #
#    Updated: 2024/02/13 16:54:22 by manufern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = ./src/push_swap.c \
	./src/ft_split.c \
	./src/ft_strlen.c \
	./src/check_numbers.c \
	./src/ft_atoi.c \
	./src/create_stack_a.c \
	./src/check_argument.c \
	./src/movement_stack_a.c \
	./src/order.c \
	./src/is_order.c \
	./src/order_two.c \
	./src/order_three.c \
	./src/order_four.c \
	./src/create_stack_b.c \
	./src/delete_node.c \
	./src/movement_stack_b.c \
	./src/order_five.c \
	./src/wallet_algorithm.c

OBJS = $(SRCS:.c=.o)
RM				= rm -f
all:			$(NAME)
$(NAME):		$(OBJS)
				$(GCC) $(CFLAGS) -o $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
