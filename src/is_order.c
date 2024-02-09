/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:41:38 by manuel            #+#    #+#             */
/*   Updated: 2024/02/08 18:26:37 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int ft_is_order(t_stack_a *stack_a)
{
	t_stack_a *current;

	current = stack_a;
	while (current != NULL)
	{
		if (current->next != NULL && current->num > current->next->num)
		{
			return 1;
		}
		current = current->next;
	}
	exit (0);
}