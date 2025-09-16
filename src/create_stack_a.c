/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:44:17 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 18:29:13 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_stack_a	*create_new_node_a(int num, int position)
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
	new_node->costo = 0;
	new_node->position = position;
	new_node->max_three = 0;
	return (new_node);
}

void	ft_lstadd_front_a(t_stack_a **lst, t_stack_a *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	(*lst)->back = new;
	new->next = *lst;
	*lst = new;
	first_to_back(*lst);
}

void	ft_lstadd_back(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*tmp;

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

void	first_to_back(t_stack_a *stack_a)
{
	t_stack_a	*aux;

	aux = stack_a;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	stack_a->back = aux;
}

void	create_stack_a(char **argv)
{
	t_stack_a	*stack_a;
	t_stack_a	*new_node;
	int			i;

	/* if (argc > 2)
		i = 1;
	else */
		i = 0;
	stack_a = NULL;
	while (argv[i])
	{
		new_node = create_new_node_a(ft_atoi(argv[i]), INT_MAX);
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	first_to_back(stack_a);
	ft_order(&stack_a);
}
