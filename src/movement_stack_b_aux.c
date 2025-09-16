/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_b_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:33:44 by manuel            #+#    #+#             */
/*   Updated: 2024/06/21 15:38:23 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	rb_rr(t_stack_b **stack_b)
{
	t_stack_b	*aux;
	int			num_aux;
	int			position_aux;

	aux = *stack_b;
	num_aux = aux->num;
	position_aux = aux->position;
	while (aux->next != NULL)
	{
		aux->num = aux->next->num;
		aux->position = aux->next->position;
		aux = aux->next;
	}
	aux->num = num_aux;
	aux->position = position_aux;
}

void	ra_rr(t_stack_a **stack_a)
{
	t_stack_a	*aux;
	int			num_aux;
	int			max_three_aux;
	int			position_aux;

	aux = *stack_a;
	num_aux = aux->num;
	max_three_aux = aux->max_three;
	position_aux = aux->position;
	while (aux->next != NULL)
	{
		aux->num = aux->next->num;
		aux->position = aux->next->position;
		aux->max_three = aux->next->max_three;
		aux = aux->next;
	}
	aux->num = num_aux;
	aux->max_three = max_three_aux;
	aux->position = position_aux;
}

void	rr(t_stack_a **stack_a, t_stack_b **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	write(1, "rr\n", 3);
	rb_rr(stack_b);
	ra_rr(stack_a);
}
