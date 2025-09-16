/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:33:44 by manuel            #+#    #+#             */
/*   Updated: 2024/06/21 15:25:57 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	pa(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_b	*temp;

	write(1, "pa\n", 3);
	if (*stack_b == NULL)
	{
		return ;
	}
	ft_lstadd_front_a(stack_a,
		create_new_node_a((*stack_b)->num, (*stack_b)->position));
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(temp);
}

void	sb(t_stack_b **stack_b)
{
	t_stack_b	*aux_stack;
	int			aux;
	int			position_aux;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	write(1, "sb\n", 3);
	aux_stack = *stack_b;
	aux = aux_stack->next->num;
	position_aux = aux_stack->next->position;
	aux_stack->next->num = aux_stack->num;
	aux_stack->num = aux;
	aux_stack->next->position = aux_stack->position;
	aux_stack->position = position_aux;
}

void	rrb(t_stack_b **stack_b)
{
	t_stack_b	*last_node;
	t_stack_b	*second_last_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	write(1, "rrb\n", 4);
	last_node = *stack_b;
	second_last_node = NULL;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *stack_b;
	*stack_b = last_node;
	second_last_node->next = NULL;
}

void	rb(t_stack_b **stack_b)
{
	t_stack_b	*aux;
	int			num_aux;
	int			position_aux;

	write(1, "rb\n", 3);
	aux = *stack_b;
	num_aux = aux->num;
	position_aux = aux->position;
	while (aux->next != NULL)
	{
		aux->num = aux->next->num;
		aux->position = aux->next->position;
		aux = aux->next;
	}
	aux->num = num_aux;
	aux->position = position_aux;
}
