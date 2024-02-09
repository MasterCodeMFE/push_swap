/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:34:20 by manuel            #+#    #+#             */
/*   Updated: 2024/02/09 18:36:26 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void delete_node_a(t_stack_a **head)
{
	t_stack_a *first_node;
	t_stack_a *second_node;
	t_stack_a *last_node;

	if (*head == NULL)
		return;
	first_node = *head;
	second_node = (*head)->next;
	if (second_node != NULL)
	{
		last_node = second_node;
		while (last_node->next != NULL)
			last_node = last_node->next;
		second_node->back = last_node;
	}
	else
		*head = NULL;
	*head = second_node;
	free(first_node);
}

void delete_node_b(t_stack_b **head)
{
    t_stack_b *first_node;
    t_stack_b *second_node;
    t_stack_b *last_node;

    if (*head == NULL)
        return;
    first_node = *head;
    second_node = (*head)->next;
    if (second_node != NULL)
    {
        last_node = second_node;
        while (last_node->next != NULL)
            last_node = last_node->next;
        second_node->back = last_node;
    }
    else
        *head = NULL;
    *head = second_node;
    free(first_node);
}
