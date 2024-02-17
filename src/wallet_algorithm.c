/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:52:15 by manufern          #+#    #+#             */
/*   Updated: 2024/02/14 19:47:03 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int count_nodes_b(t_stack_b *stack_b)
{
	t_stack_b* current;
	int count;

	current = stack_b;	
	count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void movement_for_order_aux(t_stack_a *node , t_stack_b *stack_b, int previous_num)
{	t_stack_b *current;
	int cant_nodes;
	int i;

	cant_nodes = count_nodes_b(stack_b);
	i = 0;
	current = stack_b;
	while(current->num != previous_num && previous_num != INT_MAX && previous_num != INT_MIN)
	{
		i ++;
		current = current->next;
	}
	if (i <= cant_nodes / 2)	
		node->rb = i;
	else
		node->rrb = cant_nodes - i;
	while (node->rb > 0 && node->ra > 0)
	{
		node->rb = node->rb - 1;
		node->ra = node->ra - 1;
		node->rr = node->rr + 1;
	} 
}

void movement_for_order(t_stack_a *node , t_stack_b *stack_b)
{
	t_stack_b *current;
	int previous_num;
	int next_num;
	
	next_num = INT_MAX;
	previous_num = INT_MIN;
	current = stack_b;
	printf("numero A: %i\n", node->num);
	while (current != NULL)
	{
		if (current->num < node->num && current->num > previous_num)
			previous_num = current->num;
		current = current->next;
	}
	printf("El numero %i va encima de %i\n", node->num, previous_num);
	movement_for_order_aux(node, stack_b, previous_num);
}

void print_movement(t_stack_a *head)
{
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	
	t_stack_a *current = head;
	while (current != NULL) {
		printf("ra: %d  rra: %d  pb: %d rb: %d rrb: %d rr: %d\n", current->ra, current->rra, current->pb, current->rb, current->rrb, current->rr);
		printf("coste: %d\n", current->ra + current->rra + current->pb + current->rb + current->rrb + current->rr);
		current = current->next;
	}
	printf("\n");
}

void wallet_algorithm(t_stack_a *stack_a, t_stack_b *stack_b, int cant_nodes)
{
	int i;
	int middle;
	t_stack_a  *aux_a;

	i = 0;
	if (stack_a->num > stack_a->next->num)
		sa(stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	//enpezamos con los movimientos
	aux_a = stack_a;
	cant_nodes = count_nodes(stack_a);
	middle = (cant_nodes / 2);
	while (i < cant_nodes)
	{
		if (i <= middle)
			aux_a->ra = i;
		else
			aux_a->rra = cant_nodes - i;
		aux_a->pb = 1;
		movement_for_order(aux_a, stack_b);
		i ++;
		aux_a = aux_a->next;
	}
	//terminamos con los movimientoos
	print_movement(stack_a);
	print_list_b(stack_b);
	exit (0);
}
