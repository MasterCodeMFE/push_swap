/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_copia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:26:00 by manufern          #+#    #+#             */
/*   Updated: 2024/06/24 11:39:57 by manufern         ###   ########.fr       */
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

void	smallest_to_top_aux(int min, t_stack_a *stack_a, int cant_nodes, int i)
{
	t_stack_a	*current;

	current = stack_a;
	while (current->num != min)
	{
		current = current->next;
		i++;
	}
	if (i <= (cant_nodes / 2) + 1)
	{
		while (i > 0)
		{
			ra(&stack_a);
			i--;
		}
	}
	else
	{
		while (i < cant_nodes)
		{
			rra(&stack_a);
			i++;
		}
	}
}

void	move_smallest_to_top(t_stack_a *stack_a)
{
	int			i;
	int			min;
	int			cant_nodes;
	t_stack_a	*current;

	min = stack_a->num;
	current = stack_a;
	i = 0;
	cant_nodes = 0;
	check_max_min(stack_a);
	while (current != NULL)
	{
		if (current->num < min)
		{
			min = current->num;
		}
		current = current->next;
		cant_nodes++;
	}
	smallest_to_top_aux(min, stack_a, cant_nodes, i);
	free_list(stack_a);
	exit(0);
}

int	find_position_for_first_node_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a	*current;
	int			position;

	current = stack_a;
	position = 0;
	while (!(current->num > stack_b->num && current->back->num < stack_b->num))
	{
		position++;
		current = current->next;
	}
	return (position);
}

void	put_index(t_stack_a *stack_a, int cant_nodes)
{
	t_stack_a	*aux;
	t_stack_a	*next_index;
	int			index;
	int			i;

	index = 1;
	i = 0;
	while (i < cant_nodes)
	{
		aux = stack_a;
		while (aux != NULL && aux->position != INT_MAX)
			aux = aux->next;
		next_index = aux;
		while (aux != NULL)
		{
			if (aux->position == INT_MAX && aux->num < next_index->num)
				next_index = aux;
			aux = aux->next;
		}
		next_index->position = index;
		index++;
		i++;
	}
}

void	count_move_top_a(t_stack_a *stack_a, t_stack_b *stack_b,
	int position_final_a, int position_b)
{
	t_stack_a	*aux_a;
	t_stack_b	*aux_b;
	int			med;
	int			nodes_a;
	int			i;

	nodes_a = cant_nodes_a(stack_a);
	med = nodes_a / 2;
	i = 0;
	if (nodes_a % 2 != 0)
		med++;
	aux_a = stack_a;
	while (aux_a->position != position_final_a)
	{
		i ++;
		aux_a = aux_a->next;
	}
	aux_b = stack_b;
	while (aux_b->position != position_b)
		aux_b = aux_b->next;
	if (med <= i)
		aux_b->ra = i;
	else
		aux_b->rra = ((nodes_a - i) + 1);
}

void	reset_movement(t_stack_b *stack_b)
{
	t_stack_b	*aux_b;

	aux_b = stack_b;
	while (aux_b != NULL)
	{
		aux_b->ra = 0;
		aux_b->rb = 0;
		aux_b->rr = 0;
		aux_b->rra = 0;
		aux_b->rrb = 0;
		aux_b->rrr = 0;
		aux_b->costo = 0;
		aux_b = aux_b->next;
	}
}

void	execute_moves(t_stack_a **stack_a,
	t_stack_b **stack_b, t_stack_b *aux_b)
{
	while (aux_b->ra > 0)
	{
		ra(stack_a);
		aux_b->ra--;
	}
	while (aux_b->rra > 0)
	{
		rra(stack_a);
		aux_b->rra--;
	}
	while (aux_b->rb > 0)
	{
		rb(stack_b);
		aux_b->rb--;
	}
	while (aux_b->rrb > 0)
	{
		rrb(stack_b);
		aux_b->rrb--;
	}
	while (aux_b->rr > 0)
	{
		rr(stack_a, stack_b);
		aux_b->rr--;
	}
}

void	do_movement(t_stack_a *stack_a, t_stack_b *stack_b, int move)
{
	t_stack_b	*aux_b;

	aux_b = stack_b;
	while (aux_b->costo != move)
		aux_b = aux_b->next;
	execute_moves(&stack_a, &stack_b, aux_b);
	while (aux_b->rrr > 0)
	{
		rrr(&stack_a, &stack_b);
		aux_b->rrr--;
	}
	pa(&stack_a, &stack_b);
	reset_movement(stack_b);
	if (stack_b != NULL)
		movement_to_order(stack_a, stack_b);
	move_smallest_to_top(stack_a);
}

void	find_to_move(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_b	*aux_b;
	int			move;

	aux_b = stack_b;
	move = 2147483647;
	while (aux_b != NULL)
	{
		if (aux_b-> costo < move)
			move = aux_b->costo;
		aux_b = aux_b->next;
	}
	do_movement(stack_a, stack_b, move);
}










void	position_in_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a	*aux_a;
	t_stack_b	*aux_b;
	int			position_final;
	int			movement;
	int			cant_nodes_a;

	aux_b = stack_b;
	while (aux_b != NULL)
	{
		aux_a = stack_a;
		while (aux_a->position > aux_b->position && aux_a->next != NULL)
			aux_a = aux_a->next;
		if (aux_a->position > aux_b->position && aux_a->next == NULL)
		{
			aux_a = stack_a;
			position_final = aux_a->position;
			while (aux_a != NULL)
			{
				if (aux_a->position < position_final)
					position_final = aux_a->position;
				aux_a = aux_a->next;
			}
			cant_nodes_a = count_nodes(stack_a);
			movement = 0;
			aux_a = stack_a;
			while (aux_a->position != position_final)
			{
				aux_a = aux_a->next;
				movement ++;
			}
			if (movement <= (cant_nodes_a / 2))
				aux_b->ra = movement;
			else
				aux_b->rra = ((cant_nodes_a - movement));
		}
		else
		{
				movement = 0;
				aux_a = stack_a;
				while (!(aux_a->position > aux_b->position && aux_a->back->position < aux_b->position) && aux_a->next != NULL)
				{
					aux_a = aux_a->next;
					movement ++;
				}
				cant_nodes_a = count_nodes(stack_a);
				if (movement <= (cant_nodes_a / 2))
					aux_b->ra = movement;
				else
					aux_b->rra = ((cant_nodes_a - movement));
		}
		while(aux_b->ra > 0 && aux_b->rb > 0)
		{
			aux_b->ra--; 
			aux_b->rb--;
			aux_b->rr++;
		}
		while(aux_b->rra > 0 && aux_b->rrb > 0)
		{
			aux_b->rra--;
			aux_b->rrb--;
			aux_b->rrr++;
		}
		aux_b->costo = aux_b->ra + aux_b->rra + aux_b->rb + aux_b->rrb + aux_b->rr + aux_b->rrr;
		aux_b = aux_b->next;
	}
}

































































void	movement_to_order(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int			cant_b;
	int			meed;
	t_stack_b	*aux_b;
	int			i;

	while (stack_b != NULL)
	{
		aux_b = stack_b;
		cant_b = cant_nodes_b(stack_b);
		meed = (cant_b / 2) + (cant_b % 2 != 0);
		aux_b = stack_b;
		i = 0;
		while (aux_b != NULL)
		{
			if (i < meed)
				aux_b->rb = i;
			else
				aux_b->rrb = (cant_b - i);
			aux_b = aux_b->next;
			i++;
		}
		position_in_a(stack_a, stack_b);
		find_to_move(stack_a, stack_b);
	}
}

void	wallet_algorithm_2(t_stack_a *stack_a,
	t_stack_b *stack_b, int cant_nodes)
{
	check_max_min(stack_a);
	cant_nodes = count_nodes(stack_a);
	put_index(stack_a, cant_nodes);
	while (count_nodes(stack_a) > cant_nodes / 2)
	{
		if (cant_nodes % 2 != 0 && stack_a->position <= ((cant_nodes / 2) + 1)
			&& stack_a->max_three == 0)
			pb(&stack_a, &stack_b);
		else if (stack_a->position <= (cant_nodes / 2)
			&& stack_a->max_three == 0)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
	}
	while (count_nodes(stack_a) > 3)
	{
		if (stack_a->max_three == 0)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
	}
	order_three(&stack_a);
	movement_to_order(stack_a, stack_b);
}
