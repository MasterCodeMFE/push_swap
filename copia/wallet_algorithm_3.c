/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:26:00 by manufern          #+#    #+#             */
/*   Updated: 2024/06/21 12:09:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void check_max_min(t_stack_a *stack_a)
{
	if (stack_a == NULL) {
		return; // Si el stack está vacío, no hay nada que hacer
	}

	int max = stack_a->num;
	int min = stack_a->num;
	t_stack_a *current = stack_a;

	// Encuentra el valor máximo y mínimo en el stack
	while (current != NULL) {
		if (current->num > max) {
			max = current->num;
		}
		if (current->num < min) {
			min = current->num;
		}
		current = current->next;
	}

	// Actualiza el campo max_min de cada elemento en el stack
	current = stack_a;
	while (current != NULL) {
		if (current->num == max) {
			current->max_three = 1; // El número es el mayor
		} else if (current->num == min) {
			current->max_three = 2; // El número es el menor
		} else {
			current->max_three = 0; // El número está entre los dos
		}
		current = current->next;
	}
}
void move_smallest_to_top(t_stack_a *stack_a)
{
	int i;
	int min = stack_a->num;
	int cant_nodes;
	t_stack_a *current;
	
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
		cant_nodes ++;
	}
	current = stack_a;
	while (current->num != min)
	{
		current = current->next;
		i ++;
	}
	if (i <= (cant_nodes / 2) + 1)
	{
		while (i > 0)
		{
			ra(&stack_a);
			i --;
		}
	}
	else
	{
		while (i < cant_nodes)
		{
			rra(&stack_a);
			i ++;
		}
	}
}


int find_position_for_first_node_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a *current;
	int position = 0;

	// Encuentra la posición correcta para el primer nodo de stack_b
	current = stack_a;
	
	while(!(current->num > stack_b->num && current->back->num < stack_b->num))
	{
		position ++;
		current = current->next;
	}
	return (position);
}

void wallet_algorithm_2(t_stack_a *stack_a, t_stack_b *stack_b, int cant_nodes)
{
	t_stack_a *current;
	int position;
	
	check_max_min(stack_a);
	cant_nodes = count_nodes(stack_a);
	
	while (cant_nodes > 2) {
		current = stack_a; // Reinicia el puntero current al inicio de stack_a para cada iteración
		while (current != NULL) {
			if (current->max_three == 0) {
				pb(&stack_a, &stack_b); // Asume que pb realiza la operación deseada
			} else {
				ra(&stack_a); // Asume que ra realiza la operación deseada
			}
			current = current->next; // Avanza al siguiente nodo en stack_a
		}
		cant_nodes = count_nodes(stack_a); // Actualiza el contador después de cada operación
	}
	// Mientras existan elementos en stack_b
	while (stack_b != NULL)
	{
		position = find_position_for_first_node_b(stack_a, stack_b);
		current = stack_a;
		while (current != NULL)
		{
			current = current->next;
			cant_nodes ++;
		}
		if (position <= (cant_nodes / 2) + 1)
		{
			while(position > 0)
			{
				ra(&stack_a);
				position --;
			}
		}
		else
		{
			while(position < cant_nodes)
			{
				rra(&stack_a);
				position ++;
			}
		}
		pa(&stack_a, &stack_b);
	}
	move_smallest_to_top(stack_a);
	exit(0);
}
