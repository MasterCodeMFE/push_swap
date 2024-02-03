# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manufern <manufern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 18:23:23 by manufern          #+#    #+#              #
#    Updated: 2024/02/03 11:08:27 by manufern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./src/push_swap.c \
	./src/ft_split.c \
	./src/ft_strlen.c \
	./src/check_numbers.c \
	./src/ft_atoi.c \
	./src/create_stack_a.c
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
