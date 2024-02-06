/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:53:37 by manuel            #+#    #+#             */
/*   Updated: 2024/02/05 21:27:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void ft_order_three(t_stack_a *three)
{	
	int i = ft_is_order(three);
	printf("%i", i);
    write(1, "test3\n", 6);
    
    while (ft_is_order(three))
    {

        write(1, "test\n", 5);

        if (( three->num > three->next->num) && ( three->num < three->back->num))
            sa(three);
        else
        {
			return;
        }
    }

    print_list(three);
}

/*void ft_order_three(t_stack_a *stack_a)
{
    while (is_order(stack_a) != 0)
    {
        if (stack_a != NULL && stack_a->next != NULL && stack_a->back != NULL &&
    stack_a->num > stack_a->next->num && stack_a->num < stack_a->back->num)
            sa(stack_a);
        else if (stack_a != NULL && stack_a->next != NULL && stack_a->back != NULL &&
			stack_a->num > stack_a->next->num && stack_a->next->num > stack_a->back->num)
        {
            sa(stack_a);
            ra(stack_a);
        }
        else if (stack_a != NULL && stack_a->next != NULL && stack_a->back != NULL &&
         stack_a->num < stack_a->next->num && stack_a->next->num < stack_a->back->num)

            rra(stack_a);
        else if (stack_a != NULL && stack_a->next != NULL && stack_a->back != NULL &&
			stack_a->num > stack_a->next->num && stack_a->next->num < stack_a->back->num)
            ra(stack_a);
        else if (stack_a != NULL && stack_a->next != NULL && stack_a->back != NULL &&
			stack_a->num < stack_a->next->num && stack_a->next->num > stack_a->back->num)
        {
            sa(stack_a);
            rra(stack_a);
        }
        else
        {
            print_list(stack_a);
            return;
        }
    }
}*/

void order_three(t_stack_a *stack_a)
{	
	write (1,"test1\n", 6);
	if (ft_is_order(stack_a) == 0)
		print_list(stack_a);
	else
	{	
		write (1,"test2\n", 6);
		ft_order_three(stack_a);
	}
}