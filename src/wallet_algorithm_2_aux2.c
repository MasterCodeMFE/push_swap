/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm_2_aux2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:02:30 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 17:51:39 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	smallest_to_top_aux(int min, t_stack_a *stack_a, int cant_nodes, int i)
{
	t_stack_a	*current;

	current = stack_a;
	while (current->num != min)
	{
		current = current->next;
		i++;
	}
	if (i <= (cant_nodes / 2) + 1)
	{
		while (i > 0)
		{
			ra(&stack_a);
			i--;
		}
	}
	else
	{
		while (i < cant_nodes)
		{
			rra(&stack_a);
			i++;
		}
	}
}

void	move_smallest_to_top(t_stack_a *stack_a)
{
	int			i;
	int			min;
	int			cant_nodes;
	t_stack_a	*current;

	min = stack_a->num;
	current = stack_a;
	i = 0;
	cant_nodes = 0;
	check_max_min(stack_a);
	while (current != NULL)
	{
		if (current->num < min)
		{
			min = current->num;
		}
		current = current->next;
		cant_nodes++;
	}
	smallest_to_top_aux(min, stack_a, cant_nodes, i);
	free_list(stack_a);
	exit(0);
}

int	find_position_for_first_node_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a	*current;
	int			position;

	current = stack_a;
	position = 0;
	while (!(current->num > stack_b->num && current->back->num < stack_b->num))
	{
		position++;
		current = current->next;
	}
	return (position);
}

void	put_index(t_stack_a *stack_a, int cant_nodes)
{
	t_stack_a	*aux;
	t_stack_a	*next_index;
	int			index;
	int			i;

	index = 1;
	i = 0;
	while (i < cant_nodes)
	{
		aux = stack_a;
		while (aux != NULL && aux->position != INT_MAX)
			aux = aux->next;
		next_index = aux;
		while (aux != NULL)
		{
			if (aux->position == INT_MAX && aux->num < next_index->num)
				next_index = aux;
			aux = aux->next;
		}
		next_index->position = index;
		index++;
		i++;
	}
}

void	count_move_top_a(t_stack_a *stack_a, t_stack_b *stack_b,
	int position_final_a, int position_b)
{
	t_stack_a	*aux_a;
	t_stack_b	*aux_b;
	int			med;
	int			nodes_a;
	int			i;

	nodes_a = cant_nodes_a(stack_a);
	med = nodes_a / 2;
	i = 0;
	if (nodes_a % 2 != 0)
		med++;
	aux_a = stack_a;
	while (aux_a->position != position_final_a)
	{
		i ++;
		aux_a = aux_a->next;
	}
	aux_b = stack_b;
	while (aux_b->position != position_b)
		aux_b = aux_b->next;
	if (med <= i)
		aux_b->ra = i;
	else
		aux_b->rra = ((nodes_a - i) + 1);
}
