/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_respaldo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:26:00 by manufern          #+#    #+#             */
/*   Updated: 2024/06/14 14:39:23 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

/*Hacer check_max_min pero que en vez de encontrar el menor y el mayor encuentre los trees mas grandes*/
int cant_nodes_a(t_stack_a *stack_a)
{
	int i;
	t_stack_a *aux;
	aux = stack_a;
	
	i = 0;
	while (aux != NULL)
	{
		i++;
		aux = aux->next;
	}
	printf("cantidad de nodos en a:%d\n", i);
	return (i);
}

void check_max_min(t_stack_a *stack_a)
{
	int max[3]; // Declaramos el arreglo para los tres números más grandes

	max[0] = INT_MIN;
	max[1] = INT_MIN;
	max[2] = INT_MIN;
	// Inicializamos cada elemento con el mínimo valor posible
	if (stack_a == NULL)
	{
		return; // Si el stack está vacío, no hay nada que hacer
	}

	t_stack_a *current = stack_a;

	// Encuentra los tres numeros mas altos
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

	// Ahora 'max' contiene los tres números más grandes

	// Actualiza el campo max_three de cada elemento en el stack
	current = stack_a;
	while (current != NULL)
	{
		if (current->num == max[0] || current->num == max[1] || current->num == max[2])
		{
			current->max_three = 1; // El número es uno de los tres más grandes
		}
		else
		{
			current->max_three = 0; // El número no es uno de los tres más grandes
		}
		current = current->next;
	}
}
void move_smallest_to_top(t_stack_a *stack_a)
{
	int i;
	int min = stack_a->num;
	int cant_nodes;
	t_stack_a *current;

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
			ra(stack_a);
			i--;
		}
	}
	else
	{
		while (i < cant_nodes)
		{
			rra(stack_a);
			i++;
		}
	}
}

int find_position_for_first_node_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a *current;
	int position = 0;

	// Encuentra la posición correcta para el primer nodo de stack_b
	current = stack_a;

	while (!(current->num > stack_b->num && current->back->num < stack_b->num))
	{
		position++;
		current = current->next;
	}
	return (position);
}

void put_index(t_stack_a *stack_a, int cant_nodes)
{
	t_stack_a *aux;
	t_stack_a *next_index;
	int index;
	int i;

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

void count_move_top_a(t_stack_a *stack_a, t_stack_b *stack_b, int position_final_a, int position_b)
{
	t_stack_a *aux_a;
	t_stack_b *aux_b;
	int med;
	int nodes_a;
	int i;
	print_list(stack_a); 
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
	{
		aux_b->ra = i;
	}
	else
	{
		/* printf("nodes a: %d i: %d nodo: %d\n", nodes_a, i, (nodes_a - i) + 1); */
		aux_b->rra = ((nodes_a - i) + 1);		
	}
	/* printf("rra: %d\n", aux_b->rra); */
}

void position_in_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_stack_a	*aux_a;
	t_stack_b	*aux_b;
	int			position_final;
	int			rra;

	aux_b = stack_b;
	rra = 0;
	/* printf("hola\n"); */
	while (aux_b != NULL)
	{
		aux_a = stack_a;
		while (aux_a->position > aux_b->position && aux_a->next != NULL)
		{
			/* printf("aux_a->position: %d, aux_b->position: %d\n", aux_a->position, aux_b->position); */
			aux_a = aux_a->next;
		}
		if (aux_a->position > aux_b->position && aux_a->next == NULL)
		{
			aux_a = stack_a;
			position_final = aux_a->position;
			while (aux_a != NULL)
			{
				/* printf("Checking position: %d\n", aux_a->position); */
				if (aux_a->position < position_final)
					position_final = aux_a->position;
				aux_a = aux_a->next;
			}
			printf("position_final: %d\n", position_final);
			aux_a = stack_a;
			rra = 0;
			while (aux_a->position != position_final && aux_a != NULL)
			{
				rra++;
				aux_a = aux_a->next;
			}
			printf("nodos: %d\n", (cant_nodes_a(stack_a) / 2) + 1);
			if ( cant_nodes_a(stack_a) % 2 > 0 && rra + 1 > (cant_nodes_a(stack_a) / 2) + 1)
			{
				printf("entro\n");
				rra = (cant_nodes_a(stack_a) - rra);
				aux_b->ra = rra;
			}
			else if ( cant_nodes_a(stack_a) % 2 == 0 && rra + 1 > (cant_nodes_a(stack_a) / 2))
			{
				printf("entro\n");
				rra = (cant_nodes_a(stack_a) - rra);
				aux_b->ra = rra;
			}
			else
			{
				aux_b->rra = rra;
			}
			
			printf("rra: %d\n", rra);	
			/* printf("min = %d\n", position_final); */
		}
		else
		{
			aux_a = stack_a;
			while (aux_a != NULL)
			{
				
				if (aux_a->position > aux_b->position && aux_a->back->position < aux_b->position)
				{
					printf("hola\n");
					position_final = aux_a->position;
					count_move_top_a(stack_a, stack_b, position_final, aux_b->position);
				}
				aux_a = aux_a->next;
			}
		}
		aux_b = aux_b->next;
	}
}

// Asigna valores a los campos rb y rrb de cada nodo en stack_b
// Dependiendo de si su posición en la pila está antes o después de meed
void movement_to_order(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int cant_b;
	int meed;
	t_stack_b *aux_b;
	int i;
	
	// Contar la cantidad de nodos en stack_b
	aux_b = stack_b;
	cant_b = 0;
	(void)stack_a;
	while (aux_b != NULL)
	{
		cant_b++;
		aux_b = aux_b->next;
	}
	// Calcular la posición que separa la pila en dos partes iguales
	if (cant_b % 2 != 0)
		meed = (cant_b / 2) + 1;
	else
		meed = cant_b / 2;
	// Asignar valores a ra y rra de cada nodo en stack_b
	aux_b = stack_b;
	i = 0;
	while (aux_b != NULL)
	{
		if (i < meed)
			aux_b->rb = i; // Si está antes de meed, asignar ra
		else
			aux_b->rrb = (cant_b - i); // Si está después de meed, asignar rra
		aux_b = aux_b->next;
		i++;
	}
	/* cant_a = cant_nodes_a(stack_a); */
	while (stack_b != NULL)
	{
		position_in_a(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}

void wallet_algorithm_2(t_stack_a *stack_a, t_stack_b *stack_b, int cant_nodes)
{
	t_stack_a *current;
	/* int			position; */

	check_max_min(stack_a);
	cant_nodes = count_nodes(stack_a);
	put_index(stack_a, cant_nodes);

	printf("A\n");
	print_list(stack_a);
	printf("B\n");
	print_list_b(stack_b);

	printf("nodos:%d\n", (cant_nodes / 2) + 1);
	current = stack_a;// Reinicia el puntero current al inicio de stack_a para cada iteración
	if (cant_nodes % 2 == 0)
	{
		while (count_nodes(stack_a) >= (cant_nodes / 2) + 1)
		{
			if (stack_a->position <= ((cant_nodes / 2) + 1) && stack_a->max_three == 0)
			{
				printf("antes de pb numero current: %d: %d  a: %d: %d\n", current->num, current->position, stack_a->num, stack_a->position);
				pb(&stack_a, &stack_b); // Asume que pb realiza la operación deseada
				current = stack_a;
				/* printf("numero current: %d: %d  a: %d: %d\n", current->num, current->position, stack_a->num, stack_a->position); */
			}
			else
			{
				ra(stack_a); // Asume que ra realiza la operación deseada
				/* printf("numero current: %d: %d  a: %d: %d\n", current->num, current->max_three, stack_a->num, stack_a->max_three); */
				current = stack_a;
			}
		}
	}
	else
	{
		while (count_nodes(stack_a) > (cant_nodes / 2) + 1)
		{
			if (stack_a->position <= (cant_nodes / 2) + 1 && stack_a->max_three == 0)
			{
				/* printf("antes de pb numero current: %d: %d  a: %d: %d\n", current->num, current->position, stack_a->num, stack_a->position); */
				pb(&stack_a, &stack_b); // Asume que pb realiza la operación deseada
				current = stack_a;
				/* printf("numero current: %d: %d  a: %d: %d\n", current->num, current->position, stack_a->num, stack_a->position);*/
			}
			else
			{
				ra(stack_a); // Asume que ra realiza la operación deseada
				/* printf("numero current: %d: %d  a: %d: %d\n", current->num, current->max_three, stack_a->num, stack_a->max_three); */
				current = stack_a;
			}
		}
	}
	/* printf("A\n");
	print_list(stack_a);
	printf("B\n");
	print_list_b(stack_b); */
	while (count_nodes(stack_a) > 3)
	{
		if (stack_a->max_three == 0)
		{
			pb(&stack_a, &stack_b);
		}
		else
		{
			ra(stack_a); // Asume que ra realiza la operación deseada
		}
	}
	order_three(&stack_a);
	/*printf("A\n");
	print_list(stack_a);
	printf("B\n");
	print_list_b(stack_b); */
	/* cant_nodes = count_nodes(stack_a); */ // Actualiza el contador después de cada operación

	// ver los movimientos que cuesta ordenar cada numero del stack b
	/* printf("Hola\n"); */
	/* pa(&stack_a, &stack_b); */
	movement_to_order(stack_a, stack_b);
	/* rrb(&stack_b);
	rb(&stack_b); */

	/* move_smallest_to_top(stack_a); */
	printf("final\n");
	printf("A\n");
	print_list(stack_a);
	printf("B\n");
	print_list_b(stack_b);
	exit(0);
}
