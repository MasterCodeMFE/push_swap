/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_a_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:29:41 by manufern          #+#    #+#             */
/*   Updated: 2024/06/21 14:59:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	rra_rrr(t_stack_a **stack_a)
{
	t_stack_a	*last_node;
	t_stack_a	*second_last_node;

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

void	rrb_rrr(t_stack_b **stack_b)
{
	t_stack_b	*last_node;
	t_stack_b	*second_last_node;

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

void	rrr(t_stack_a **stack_a, t_stack_b **stack_b)
{
	write(1, "rrr\n", 4);
	rra_rrr(stack_a);
	rrb_rrr(stack_b);
}
