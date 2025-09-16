/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm_2_aux3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:03:41 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 17:51:45 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	reset_movement(t_stack_b *stack_b)
{
	t_stack_b	*aux_b;

	aux_b = stack_b;
	while (aux_b != NULL)
	{
		aux_b->ra = 0;
		aux_b->rb = 0;
		aux_b->rr = 0;
		aux_b->rra = 0;
		aux_b->rrb = 0;
		aux_b->rrr = 0;
		aux_b->costo = 0;
		aux_b = aux_b->next;
	}
}

void	execute_moves(t_stack_a **stack_a,
	t_stack_b **stack_b, t_stack_b *aux_b)
{
	while (aux_b->ra > 0)
	{
		ra(stack_a);
		aux_b->ra--;
	}
	while (aux_b->rra > 0)
	{
		rra(stack_a);
		aux_b->rra--;
	}
	while (aux_b->rb > 0)
	{
		rb(stack_b);
		aux_b->rb--;
	}
	while (aux_b->rrb > 0)
	{
		rrb(stack_b);
		aux_b->rrb--;
	}
	while (aux_b->rr > 0)
	{
		rr(stack_a, stack_b);
		aux_b->rr--;
	}
}

void	do_movement(t_stack_a *stack_a, t_stack_b *stack_b, int move)
{
	t_stack_b	*aux_b;

	aux_b = stack_b;
	while (aux_b->costo != move)
		aux_b = aux_b->next;
	execute_moves(&stack_a, &stack_b, aux_b);
	while (aux_b->rrr > 0)
	{
		rrr(&stack_a, &stack_b);
		aux_b->rrr--;
	}
	pa(&stack_a, &stack_b);
	reset_movement(stack_b);
	if (stack_b != NULL)
		movement_to_order(stack_a, stack_b);
	move_smallest_to_top(stack_a);
}

void	find_to_move(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_b	*aux_b;
	int			move;

	aux_b = stack_b;
	move = 2147483647;
	while (aux_b != NULL)
	{
		if (aux_b-> costo < move)
			move = aux_b->costo;
		aux_b = aux_b->next;
	}
	do_movement(stack_a, stack_b, move);
}

void	move_up_or_down(t_stack_a *stack_a, t_stack_b *aux_b)
{
	int			movement;
	int			position_final;
	int			cant_nodes_a;
	t_stack_a	*aux_a;

	aux_a = stack_a;
	position_final = aux_a->position;
	while (aux_a != NULL)
	{
		if (aux_a->position < position_final)
			position_final = aux_a->position;
		aux_a = aux_a->next;
	}
	cant_nodes_a = count_nodes(stack_a);
	movement = 0;
	aux_a = stack_a;
	while (aux_a->position != position_final)
	{
		aux_a = aux_a->next;
		movement++;
	}
	if (movement <= (cant_nodes_a / 2))
		aux_b->ra = movement;
	else
		aux_b->rra = cant_nodes_a - movement;
}
