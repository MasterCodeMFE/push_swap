/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:40 by manuel            #+#    #+#             */
/*   Updated: 2024/02/08 20:07:42 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_stack_b	*create_new_node_b(int num)
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
	printf("%i\n", new_node->num);
	return (new_node);
}

void print_list_b(t_stack_b *head) {
    if (head == NULL) {
        printf("List B is empty.\n");
        return;
    }

    t_stack_b *current = head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

void ft_lstadd_front(t_stack_b **lst, t_stack_b *new)
{   
    new->next = *lst;
    *lst = new;
    printf("%i\n",(*lst)->num);
}