/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:45:31 by manufern          #+#    #+#             */
/*   Updated: 2024/02/08 20:10:39 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void move_min_to_b(t_stack_a *stack_a, int movement, t_stack_b *stack_b)
{
	print_list(stack_a);
	if (movement == 1)
		write(1,"hola\n",6);
	else if (movement == 2)
		ra(stack_a);
	else if (movement == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (movement == 4)
		rra(stack_a);
	ft_is_order(stack_a);
	pb(stack_a, &stack_b);
	write(1,"\n\n\n",3);
	print_list(stack_a);
	write(1,"a\n\n\n",4);
	print_list_b(stack_b);
	write(1,"b\n\n\n",4);
	print_list(stack_a);
}

void get_min_to_stack_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int			min_position;
	int			current_position;
	int			min_value;
	t_stack_a	*current;
	
	min_position = 1;
	current_position = 1;
	min_value = stack_a->num;
	current = stack_a->next;
	while (current != NULL)
	{
		if (current->num < min_value)
		{
			min_value = current->num;
			min_position = current_position;
		}
		current = current->next;
		current_position++;
	}
	move_min_to_b(stack_a, min_position + 1, stack_b);
}

void order_four(t_stack_a *stack_a, t_stack_b *stack_b)
{
	get_min_to_stack_b(stack_a, stack_b);
	/*order_three(stack_a);*/
}