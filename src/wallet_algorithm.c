/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:52:15 by manufern          #+#    #+#             */
/*   Updated: 2024/02/13 20:19:55 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"
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
        if (current->num > node->num && current->num < next_num)
        {
            next_num = current->num;
        }
        if (current->num < node->num && current->num > previous_num)
        {
            previous_num = current->num;
        }
        current = current->next;
    }
	printf("El numero %i va encima de %i\n", node->num, previous_num);
	
}

void print_movement(t_stack_a *head)
{
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	
	t_stack_a *current = head;
	while (current != NULL) {
		printf("ra: %d  rra: %d  pb: %d\n", current->ra, current->rra, current->pb);
		current = current->next;
	}
	printf("\n");
}

void wallet_algorithm(t_stack_a *stack_a, t_stack_b *stack_b, int cant_nodes)
{
	(void)stack_b;
	int i;
	int middle;
	t_stack_a  *aux_a;

	i = 0;
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
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
	print_movement(stack_a);
	print_list_b(stack_b);
	exit (0);
}
