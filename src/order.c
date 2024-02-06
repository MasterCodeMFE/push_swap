/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:08:47 by manuel            #+#    #+#             */
/*   Updated: 2024/02/05 20:03:31 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int count_nodes(t_stack_a* stack_a)
{
	t_stack_a* current;
	int count;

	current = stack_a;	
	count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void ft_order(t_stack_a *stack_a)
{
	int			cant_nodes;
	/* t_stack_b	*stack_b; */
	
	cant_nodes = count_nodes(stack_a);
	/* printf("%d", cant_nodes); */
	if (cant_nodes == 2)
	{
		order_two(stack_a);
	}
	else if(cant_nodes == 3)
	{	
		write (1,"test\n", 5);
		order_three(stack_a);
	}
	else
		print_list(stack_a);
}
