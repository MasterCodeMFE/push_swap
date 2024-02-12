/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:45:31 by manufern          #+#    #+#             */
/*   Updated: 2024/02/11 11:54:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void move_min_to_b(t_stack_a **stack_a, int movement, t_stack_b **stack_b)
{
	if (movement == 2)
		ra(*stack_a);
	else if (movement == 3)
	{
		ra(*stack_a);
		ra(*stack_a);
	}
	else if (movement == 4)
		rra(*stack_a);
	ft_is_order(*stack_a);
	pb(&*stack_a, &*stack_b);
}

void get_min_to_stack_b(t_stack_a **stack_a, t_stack_b **stack_b)
{
	int			min_position;
	int			current_position;
	int			min_value;
	t_stack_a	*current;
	
	min_position = 0;
	current_position = 1;
	min_value = (*stack_a)->num;
	current = (*stack_a)->next;
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
	move_min_to_b(&*stack_a, min_position + 1, &*stack_b);
}

void order_four(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (ft_is_order(stack_a) == 1)
	{
	get_min_to_stack_b(&stack_a, &stack_b);
	ft_order_three(&stack_a);
	pa(&stack_a, &stack_b);
	}	
	/* write(1,"\n\n\n",3);
	print_list(stack_a);
	write(1,"a\n\n\n",4);
	print_list_b(stack_b);
	write(1,"b\n\n\n",4); */

}
