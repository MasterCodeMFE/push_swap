/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:53:37 by manuel            #+#    #+#             */
/*   Updated: 2024/02/09 19:41:38 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void ft_order_three(t_stack_a **three)
{	
	int i = ft_is_order(*three);
	while (i == 1)
	{
		
		if (( (*three)->num > (*three)->next->num) && ( (*three)->num < (*three)->back->num))
			sa(*three);
		else if (( (*three)->num > (*three)->next->num) && ( (*three)->num > (*three)->back->num))
			ra(*three);
		else if (( (*three)->num < (*three)->next->num) && ( (*three)->num < (*three)->back->num))
			rra(*three);
		else if (( (*three)->num < (*three)->next->num) && ( (*three)->num > (*three)->back->num))
			rra(*three);
		i = ft_is_order(*three);
	}
}

void order_three(t_stack_a **stack_a)
{	
	print_list(*stack_a);
	if (ft_is_order(*stack_a) == 0)
	{
		print_list(*stack_a);
		exit (0);
	}
	else	
		ft_order_three(&*stack_a);
	print_list(*stack_a);
}
