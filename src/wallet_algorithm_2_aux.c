/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm_2_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:00:32 by manufern          #+#    #+#             */
/*   Updated: 2024/06/25 17:50:28 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	cant_nodes_a(t_stack_a *stack_a)
{
	int			i;
	t_stack_a	*aux;

	aux = stack_a;
	i = 0;
	while (aux != NULL)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

int	cant_nodes_b(t_stack_b *stack_b)
{
	int			i;
	t_stack_b	*aux;

	aux = stack_b;
	i = 0;
	while (aux != NULL)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	check_max_three_aux(t_stack_a *stack_a, int *max)
{
	t_stack_a	*current;

	current = stack_a;
	while (current != NULL)
	{
		if (current->num > max[0])
		{
			max[2] = max[1];
			max[1] = max[0];
			max[0] = current->num;
		}
		else if (current->num > max[1])
		{
			max[2] = max[1];
			max[1] = current->num;
		}
		else if (current->num > max[2])
		{
			max[2] = current->num;
		}
		current = current->next;
	}
}

void	check_max_three_aux_2(t_stack_a *stack_a, int *max)
{
	t_stack_a	*current;

	current = stack_a;
	while (current != NULL)
	{
		if (current->num == max[0] || current->num == max[1]
			|| current->num == max[2])
		{
			current->max_three = 1;
		}
		else
		{
			current->max_three = 0;
		}
		current = current->next;
	}
}

void	check_max_min(t_stack_a *stack_a)
{
	int			max[3];

	max[0] = INT_MIN;
	max[1] = INT_MIN;
	max[2] = INT_MIN;
	if (stack_a == NULL)
	{
		return ;
	}
	check_max_three_aux(stack_a, max);
	check_max_three_aux_2(stack_a, max);
}
