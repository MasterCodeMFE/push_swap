/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:44:17 by manufern          #+#    #+#             */
/*   Updated: 2024/02/03 13:08:15 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_stack_a	*create_new_node(int num)
{
	t_stack_a	*new_node;

	new_node = malloc(sizeof(t_stack_a));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->num = num;
	new_node->next = NULL;
	new_node->back = NULL;
	return (new_node);
}

void ft_lstadd_back(t_stack_a **lst, t_stack_a *new)
{
    t_stack_a *tmp;

    if (*lst == NULL)
    {
        *lst = new;
        new->next = NULL;
        new->back = NULL;
    }
    else
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
        new->next = NULL;
        new->back = tmp;
    }
}

void print_list(t_stack_a *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Para listas no circulares
    t_stack_a *current = head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

void    create_stack_a(int argc, char **argv)
{
	t_stack_a   *stack_a;
	t_stack_a   *new_node;
	int			i;

    if (argc > 2)
	    i = 1;
    else
        i = 0;
	stack_a = NULL;
	while (argv[i])
	{
		new_node = create_new_node(ft_atoi(argv[i]));
		ft_lstadd_back(&stack_a, new_node);
		i ++;
	}
	print_list(stack_a);
}