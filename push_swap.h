/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:34 by manufern          #+#    #+#             */
/*   Updated: 2024/02/03 13:09:12 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

#endif