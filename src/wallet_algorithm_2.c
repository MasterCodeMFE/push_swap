/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:26:00 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 17:51:54 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	calculate_movement(t_stack_a *stack_a, t_stack_b *aux_b)
{
	int			movement;
	int			cant_nodes_a;
	t_stack_a	*aux_a;

	movement = 0;
	aux_a = stack_a;
	while (!(aux_a->position > aux_b->position
			&& aux_a->back->position < aux_b->position) && aux_a->next != NULL)
	{
		aux_a = aux_a->next;
		movement++;
	}
	cant_nodes_a = count_nodes(stack_a);
	if (movement <= (cant_nodes_a / 2))
		aux_b->ra = movement;
	else
		aux_b->rra = cant_nodes_a - movement;
}

void	reduce_simultaneous_rotations(t_stack_b *aux_b)
{
	while (aux_b->ra > 0 && aux_b->rb > 0)
	{
		aux_b->ra--;
		aux_b->rb--;
		aux_b->rr++;
	}
	while (aux_b->rra > 0 && aux_b->rrb > 0)
	{
		aux_b->rra--;
		aux_b->rrb--;
		aux_b->rrr++;
	}
}

void	position_in_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a	*aux_a;
	t_stack_b	*aux_b;

	aux_b = stack_b;
	while (aux_b != NULL)
	{
		aux_a = stack_a;
		while (aux_a->position > aux_b->position && aux_a->next != NULL)
			aux_a = aux_a->next;
		if (aux_a->position > aux_b->position && aux_a->next == NULL)
			move_up_or_down(stack_a, aux_b);
		else
			calculate_movement(stack_a, aux_b);
		reduce_simultaneous_rotations(aux_b);
		aux_b->costo = aux_b->ra + aux_b->rra + aux_b->rb;
		aux_b->costo = aux_b->costo + aux_b->rrb + aux_b->rr + aux_b->rrr;
		aux_b = aux_b->next;
	}
}

void	movement_to_order(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int			cant_b;
	int			meed;
	t_stack_b	*aux_b;
	int			i;

	while (stack_b != NULL)
	{
		aux_b = stack_b;
		cant_b = cant_nodes_b(stack_b);
		meed = (cant_b / 2) + (cant_b % 2 != 0);
		aux_b = stack_b;
		i = 0;
		while (aux_b != NULL)
		{
			if (i < meed)
				aux_b->rb = i;
			else
				aux_b->rrb = (cant_b - i);
			aux_b = aux_b->next;
			i++;
		}
		position_in_a(stack_a, stack_b);
		find_to_move(stack_a, stack_b);
	}
}

void	wallet_algorithm_2(t_stack_a *stack_a,
	t_stack_b *stack_b, int cant_nodes)
{
	if (ft_is_order(stack_a) == 0)
		return ;
	check_max_min(stack_a);
	cant_nodes = count_nodes(stack_a);
	put_index(stack_a, cant_nodes);
	while (count_nodes(stack_a) > cant_nodes / 2)
	{
		if (cant_nodes % 2 != 0 && stack_a->position <= ((cant_nodes / 2) + 1)
			&& stack_a->max_three == 0)
			pb(&stack_a, &stack_b);
		else if (stack_a->position <= (cant_nodes / 2)
			&& stack_a->max_three == 0)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
	}
	while (count_nodes(stack_a) > 3)
	{
		if (stack_a->max_three == 0)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
	}
	order_three(&stack_a);
	movement_to_order(stack_a, stack_b);
}
