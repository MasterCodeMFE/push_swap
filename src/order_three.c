/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:53:37 by manuel            #+#    #+#             */
/*   Updated: 2024/06/22 10:48:40 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_order_three(t_stack_a **three)
{
	int	i;

	i = ft_is_order(*three);
	while (i == 1)
	{
		if (((*three)->num > (*three)->next->num)
			&& ((*three)->num < (*three)->back->num))
			sa(three);
		else if (((*three)->num > (*three)->next->num)
			&& ((*three)->num > (*three)->back->num))
			ra(three);
		else if (((*three)->num < (*three)->next->num)
			&& ((*three)->num < (*three)->back->num))
			rra(three);
		else if (((*three)->num < (*three)->next->num)
			&& ((*three)->num > (*three)->back->num))
			rra(three);
		i = ft_is_order(*three);
	}
}

void	order_three(t_stack_a **stack_a)
{
	if (ft_is_order(*stack_a) == 0)
		return ;
	else
		ft_order_three(&*stack_a);
}
