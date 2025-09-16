# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manufern <manufern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 18:23:23 by manufern          #+#    #+#              #
#    Updated: 2024/06/25 19:15:19 by manufern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
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
       ./src/movement_stack_a_aux.c \
       ./src/movement_stack_b_aux.c \
       ./src/wallet_algorithm_2_aux.c \
       ./src/wallet_algorithm_2_aux2.c \
       ./src/wallet_algorithm_2_aux3.c \
       ./src/wallet_algorithm_2.c

OBJDIR := src/obj
OBJS := $(patsubst ./src/%.c,$(OBJDIR)/%.o,$(SRCS))
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: ./src/%.c
	@mkdir -p $(OBJDIR)
	@$(GCC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
