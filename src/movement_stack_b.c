/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:33:44 by manuel            #+#    #+#             */
/*   Updated: 2024/02/09 19:41:53 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void pa(t_stack_a **stack_a, t_stack_b **stack_b)
	{
		write(1, "pa\n", 3);
		ft_lstadd_front_a(&*stack_a, create_new_node_a((*stack_b)->num));
		delete_node_b(&*stack_b);
	}
	