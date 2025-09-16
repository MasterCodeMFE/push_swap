/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:29:41 by manufern          #+#    #+#             */
/*   Updated: 2024/06/21 14:32:35 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	sa(t_stack_a **stack_a)
{
	t_stack_a	*aux_stack;
	int			aux;
	int			position_aux;

	write (1, "sa\n", 3);
	aux_stack = *stack_a;
	aux = aux_stack->next->num;
	position_aux = aux_stack->next->position;
	aux_stack->next->num = aux_stack->num;
	aux_stack->num = aux;
	aux_stack->next->position = aux_stack->position;
	aux_stack->position = position_aux;
}

void	rra(t_stack_a **stack_a)
{
	t_stack_a	*last_node;
	t_stack_a	*second_last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	write(1, "rra\n", 4);
	last_node = *stack_a;
	second_last_node = NULL;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *stack_a;
	*stack_a = last_node;
	second_last_node->next = NULL;
}

void	ra(t_stack_a **stack_a)
{
	t_stack_a	*aux;
	int			num_aux;
	int			max_three_aux;
	int			position_aux;

	write(1, "ra\n", 3);
	aux = *stack_a;
	num_aux = aux->num;
	max_three_aux = aux->max_three;
	position_aux = aux->position;
	while (aux->next != NULL)
	{
		aux->num = aux->next->num;
		aux->position = aux->next->position;
		aux->max_three = aux->next->max_three;
		aux = aux->next;
	}
	aux->num = num_aux;
	aux->max_three = max_three_aux;
	aux->position = position_aux;
}

void	pb(t_stack_a **stack_a, t_stack_b **stack_b)
{
	write(1, "pb\n", 3);
	ft_lstadd_front(stack_b,
		create_new_node_b((*stack_a)->num, (*stack_a)->position));
	delete_node_a(stack_a);
}
