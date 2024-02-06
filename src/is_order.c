/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:41:38 by manuel            #+#    #+#             */
/*   Updated: 2024/02/05 21:25:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

bool ft_is_order(t_stack_a *stack_a)
{
    t_stack_a *current;

    current = stack_a;
    while (current != NULL)
    {
        if (current->next != NULL && current->num > current->next->num)
        {
            return false;
        }
        current = current->next;
    }
    

    return true;
}