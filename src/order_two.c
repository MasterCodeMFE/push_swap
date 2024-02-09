/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:48:45 by manuel            #+#    #+#             */
/*   Updated: 2024/02/08 15:50:19 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void order_two(t_stack_a *stack_a)
{
	if (stack_a->num > stack_a->next->num)
	{
		sa(stack_a);
	}
	print_list(stack_a);
}