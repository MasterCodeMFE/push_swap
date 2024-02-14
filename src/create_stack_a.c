/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:44:17 by manufern          #+#    #+#             */
/*   Updated: 2024/02/13 17:04:44 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_stack_a	*create_new_node_a(int num)
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
	return (new_node);
}

void ft_lstadd_front_a(t_stack_a **lst, t_stack_a *new)
{   
	(*lst)->back = new;
	new->next = *lst;
	*lst = new;
	first_to_back(*lst);
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

void print_list(t_stack_a *head)
{
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	
	t_stack_a *current = head;
	while (current != NULL) {
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");
}

void first_to_back(t_stack_a *stack_a)
{
	t_stack_a *aux;

	aux = stack_a;
	while (aux->next != NULL) {
		aux = aux->next;
	}
	stack_a->back = aux;
}

void    create_stack_a(int argc, char **argv)
{
	t_stack_a   *stack_a;
	t_stack_a   *new_node;
	int			i;

	if (argc > 2)
		i = 1;
	else
	{
		i = 0;
	}
	stack_a = NULL;
	while (argv[i])
	{
		new_node = create_new_node_a(ft_atoi(argv[i]));
		ft_lstadd_back(&stack_a, new_node);
		i ++;
	}
	first_to_back(stack_a);
	ft_order(stack_a);
}
