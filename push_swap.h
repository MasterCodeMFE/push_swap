/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:34 by manufern          #+#    #+#             */
/*   Updated: 2024/02/08 20:05:58 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <stdbool.h>

typedef struct s_stack_a
{
	int                 num;
	struct s_stack_a	*back;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int                 num;
	struct s_stack_b	*back;
	struct s_stack_b	*next;
}	t_stack_b;

void comprobate_argument(int argc, char **argv);
int is_number(char *number);
int are_arguments_equal(char *arg1, char *arg2);
char *drop_cero(char *num);
size_t	ft_strlen(const char *s);
int ft_counter (char **argv);
int	ft_string_count(char const *s, char c);
int	ft_word_count(char const *s, char c, int i);
char	**ft_free(char **aux, int j);
char	**ft_matrix(char **aux, char const *s, char c, int i);
char	**ft_split(char const *s, char c);
char *drop_cero(char *num);
int	ft_atoi(const char *str);
void    create_stack_a(int argc, char **argv);
void ft_check_one_argument(char **argv);
void check_is_number (int i, int argc, char ** argv);
int is_number(char *number);
char *drop_cero(char *num);
void sa(t_stack_a *stack_a);
void rra(t_stack_a *stack_a);
void ra(t_stack_a *stack_a);
void ft_order(t_stack_a *stack_a);
int ft_is_order(t_stack_a *stack_a);
void order_two(t_stack_a *stack_a);
void order_three(t_stack_a *stack_a);
void order_four(t_stack_a *stack_a, t_stack_b *stack_b);
void ft_lstadd_front(t_stack_b **lst, t_stack_b *new);
t_stack_b	*create_new_node_b(int num);
void pb(t_stack_a *stack_a, t_stack_b **stack_b);









void print_list(t_stack_a *head);
void print_list_b(t_stack_b *head);
#endif