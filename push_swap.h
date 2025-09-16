/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:34 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 18:29:20 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_a
{
	int					num;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					costo;
	int					max_three;
	int					position;
	struct s_stack_a	*back;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int					num;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					costo;
	int					position;
	struct s_stack_b	*back;
	struct s_stack_b	*next;
}	t_stack_b;

char		*drop_cero(char *num);
int			is_number(char *number);
void		check_is_number(int i, int argc, char **argv);
void	comprobate_argument(int argc, char **argv);
void		ft_check_one_argument(char **argv);
char		*handle_negative_zero(char *arg);
char		*remove_leading_zeros(char *arg);
int			compare_arguments(char *arg1, char *arg2);
int			are_arguments_equal(char *arg1, char *arg2);
t_stack_a	*create_new_node_a(int num, int position);
void		ft_lstadd_front_a(t_stack_a **lst, t_stack_a *new);
void		ft_lstadd_back(t_stack_a **lst, t_stack_a *new);
void		first_to_back(t_stack_a *stack_a);
void		create_stack_a(char **argv);
t_stack_b	*create_new_node_b(int num, int position);
void		ft_lstadd_front(t_stack_b **lst, t_stack_b *new);
void		delete_node_a(t_stack_a **head);
void		delete_node_b(t_stack_b **head);
void		free_list(t_stack_a *head);
void		print_error(void);
int			ft_atoi(const char *str);
int			ft_string_count(char const *s, char c);
int			ft_word_count(char const *s, char c, int i);
char		**ft_free(char **aux);
char		**ft_matrix(char **aux, char const *s, char c, int i);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
int			ft_counter(char **argv);
int			ft_is_order(t_stack_a *stack_a);
void		rra_rrr(t_stack_a **stack_a);
void		rrb_rrr(t_stack_b **stack_b);
void		rrr(t_stack_a **stack_a, t_stack_b **stack_b);
void		sa(t_stack_a **stack_a);
void		rra(t_stack_a **stack_a);
void		ra(t_stack_a **stack_a);
void		pb(t_stack_a **stack_a, t_stack_b **stack_b);
void		rb_rr(t_stack_b **stack_b);
void		ra_rr(t_stack_a **stack_a);
void		rr(t_stack_a **stack_a, t_stack_b **stack_b);
void		pa(t_stack_a **stack_a, t_stack_b **stack_b);
void		sb(t_stack_b **stack_b);
void		rrb(t_stack_b **stack_b);
void		rb(t_stack_b **stack_b);
void		move_to_b(t_stack_a **stack_a, int movement, t_stack_b **stack_b);
void		min_to_stack_b(t_stack_a **stack_a, t_stack_b **stack_b);
void		order_five(t_stack_a **stack_a,
				t_stack_b **stack_b);
void		move_min_to_b(t_stack_a **stack_a,
				int movement, t_stack_b **stack_b);
void		get_min_to_stack_b(t_stack_a **stack_a, t_stack_b **stack_b);
void		order_four(t_stack_a **stack_a, t_stack_b **stack_b);
void		ft_order_three(t_stack_a **three);
void		order_three(t_stack_a **stack_a);
void		order_two(t_stack_a **stack_a);
int			count_nodes(t_stack_a *stack_a);
int			count_nodes_b(t_stack_b *stack_b);
void		ft_order(t_stack_a **stack_a);
int			ft_count_words(char **argument);
int			main(int argc, char **argv);
int			cant_nodes_a(t_stack_a *stack_a);
int			cant_nodes_b(t_stack_b *stack_b);
void		check_max_three_aux(t_stack_a *stack_a, int *max);
void		check_max_three_aux_2(t_stack_a *stack_a, int *max);
void		check_max_min(t_stack_a *stack_a);
void		smallest_to_top_aux(int min, t_stack_a *stack_a,
				int cant_nodes, int i);
void		move_smallest_to_top(t_stack_a *stack_a);
int			find_position_for_first_node_b(t_stack_a *stack_a,
				t_stack_b *stack_b);
void		put_index(t_stack_a *stack_a, int cant_nodes);
void		count_move_top_a(t_stack_a *stack_a, t_stack_b *stack_b,
				int position_final_a, int position_b);
void		reset_movement(t_stack_b *stack_b);
void		execute_moves(t_stack_a **stack_a,
				t_stack_b **stack_b, t_stack_b *aux_b);
void		do_movement(t_stack_a *stack_a, t_stack_b *stack_b, int move);
void		find_to_move(t_stack_a *stack_a, t_stack_b *stack_b);
void		move_up_or_down(t_stack_a *stack_a, t_stack_b *aux_b);
void		calculate_movement(t_stack_a *stack_a, t_stack_b *aux_b);
void		reduce_simultaneous_rotations(t_stack_b *aux_b);
void		position_in_a(t_stack_a *stack_a, t_stack_b *stack_b);
void		movement_to_order(t_stack_a *stack_a, t_stack_b *stack_b);
void		wallet_algorithm_2(t_stack_a *stack_a,
				t_stack_b *stack_b, int cant_nodes);
void		write_error(void);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
