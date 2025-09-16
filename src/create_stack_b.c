/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:40 by manuel            #+#    #+#             */
/*   Updated: 2024/06/24 12:08:26 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_stack_b	*create_new_node_b(int num, int position)
{
	t_stack_b	*new_node;

	new_node = malloc(sizeof(t_stack_b));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->num = num;
	new_node->next = NULL;
	new_node->back = NULL;
	new_node->sa = 0;
	new_node->sb = 0;
	new_node->ss = 0;
	new_node->pa = 0;
	new_node->pb = 0;
	new_node->ra = 0;
	new_node->rb = 0;
	new_node->rr = 0;
	new_node->rra = 0;
	new_node->rrb = 0;
	new_node->rrr = 0;
	new_node->costo = 0;
	new_node->position = position;
	return (new_node);
}

void	ft_lstadd_front(t_stack_b **lst, t_stack_b *new)
{
	new->next = *lst;
	if (*lst != NULL)
	{
		(*lst)->back = new;
	}
	else
	{
		new->back = NULL;
	}
	*lst = new;
	if ((*lst)->back == NULL || (*lst)->next == NULL)
	{
		(*lst)->back = *lst;
	}
}
