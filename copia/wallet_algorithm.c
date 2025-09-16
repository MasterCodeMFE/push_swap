/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:52:15 by manufern          #+#    #+#             */
/*   Updated: 2024/06/21 12:09:32 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int min_numomax_num(t_stack_a **stack_a, int num_b)
{
    t_stack_a *aux;

    aux = *stack_a;
    if (num_b > aux->back->num)
        return (1);
    else if (num_b < aux->back->num)
        return (2);
    return (0);
}

/* void transfer_sorted_from_b_to_a(t_stack_a **stack_a, t_stack_b **stack_b)
{
	
} */


void ft_order_three_w(t_stack_a **three)
{	
	int i = ft_is_order(*three);
	/* print_list(*three); */
	while (i == 1)
	{
		
		if (( (*three)->num > (*three)->next->num) && ( (*three)->num < (*three)->back->num))
			sa(three);
		else if (( (*three)->num > (*three)->next->num) && ( (*three)->num > (*three)->back->num))
			ra(three);
		else if (( (*three)->num < (*three)->next->num) && ( (*three)->num < (*three)->back->num))
			rra(three);
		else if (( (*three)->num < (*three)->next->num) && ( (*three)->num > (*three)->back->num))
			rra(three);
		i = ft_is_order(*three);
	}
}

void order_three_w(t_stack_a **stack_a)
{	
	/* print_list(*stack_a); */
	if (ft_is_order(*stack_a) == 0)
	{
		/* print_list(*stack_a); */
		return ;
	}
	else	
		ft_order_three_w(&*stack_a);
}

void reset_cost(t_stack_a **stack_a)
{
	t_stack_a *aux;

	aux = *stack_a;
	while (aux != NULL)
    {
		aux->sa = 0;
		aux->sb = 0;
		aux->ss = 0;
		aux->pa = 0;
		aux->pb = 0;
		aux->ra = 0;
		aux->rb = 0;
		aux->rr = 0;
		aux->rra = 0;
		aux->rrb = 0;
		aux->rrr = 0;
		aux->costo = 0;
        aux = aux->next;
    }
}

void move_a_b(t_stack_a **stack_a, t_stack_b **stack_b, int poss)
{
    t_stack_a *aux_a;
    int i;

    i = 1;
    aux_a = *stack_a;
    while (i < poss && aux_a != NULL)
    {
        aux_a = aux_a->next;
        i++;
    }

    if (aux_a == NULL)
    {
        // Verificar si aux_a es NULL para evitar acceder a memoria no válida
        return;
    }

    while (aux_a->ra > 0)
    {
        ra(&stack_a); // Cambiar stack_a a *stack_a
        aux_a->ra--;
    }

    while (aux_a->rra > 0)
    {
        rra(stack_a); // Cambiar stack_a a *stack_a
        aux_a->rra--;
    }

    while (aux_a->rr > 0)
    {
        rr(stack_a, stack_b);
        aux_a->rr--;
    }

    while (aux_a->rrr > 0)
    {
        rrr(stack_a, stack_b);
        aux_a->rrr--;
    }
    pb(stack_a, stack_b);
    reset_cost(stack_a);
}


void node_to_move_tob_b(t_stack_a **stack_a, t_stack_b **stack_b)
{
    int poss; // Inicializar poss a 1 para la primera posición
    int coste; // Inicializar coste con el valor máximo posible para asegurar que cualquier costo sea menor
    int i;
    t_stack_a *aux;
    

	poss = 1;
	coste = INT_MAX;
	i = 1;
	aux = *stack_a;
    (void) *stack_b; // Ignorar stack_b si no se utiliza
    
    while (aux != NULL)
    {
        if (coste > aux->costo) // Asegurarse de que coste se actualice correctamente
        {
            poss = i; // Actualizar poss con la posición actual
            coste = aux->costo; // Actualizar coste con el nuevo costo mínimo
        }
        aux = aux->next;
        i++;
    }
    move_a_b(&*stack_a, &*stack_b, poss);
   /*  printf("La posición del nodo con el menor costo es: %d\n", poss); */
}

void count_costo_a(t_stack_a *stack_a)
{
	t_stack_a	*aux;
	
	aux = stack_a;
	while (aux != NULL)
	{
		aux->costo = aux->ra + aux->rra + aux->pb + aux->rb + aux->rrb + aux->rr;
		aux = aux->next;
	}
}

int count_nodes_b(t_stack_b *stack_b)
{
	t_stack_b* current;
	int count;

	current = stack_b;	
	count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

void movement_for_order_aux(t_stack_a *node , t_stack_b *stack_b, int previous_num)
{	t_stack_b *current;
	int cant_nodes;
	int i;

	cant_nodes = count_nodes_b(stack_b);
	i = 0;
	current = stack_b;
	while(current->num != previous_num && previous_num != INT_MAX && previous_num != INT_MIN)
	{
		i ++;
		current = current->next;
	}
	if (i <= cant_nodes / 2)	
		node->rb = i;
	else
		node->rrb = cant_nodes - i;
	while (node->rb > 0 && node->ra > 0)
	{
		node->rb = node->rb - 1;
		node->ra = node->ra - 1;
		node->rr = node->rr + 1;
	}
	while (node->rrb > 0 && node->rra > 0)
	{
		node->rrb = node->rrb - 1;
		node->rra = node->rra - 1;
		node->rrr = node->rrr + 1;
	} 
}

void movement_for_order(t_stack_a *node , t_stack_b *stack_b)
{
	t_stack_b *current;
	int previous_num;
	/* int next_num; */
	
	/* next_num = INT_MAX; */
	previous_num = INT_MAX;
	current = stack_b;
	/* printf("numero A: %i\n", node->num); */
	while (current != NULL)
	{
		if (current->num < node->num && current->num > previous_num)
			previous_num = current->num;
		current = current->next;
	}
	/* printf("El numero %i va encima de %i\n", node->num, previous_num); */
	movement_for_order_aux(node, stack_b, previous_num);
	
}

void print_movement(t_stack_a *head)
{
	if (head == NULL) {
		/* printf("List is empty.\n"); */
		return;
	}
	
	t_stack_a *current = head;
	while (current != NULL) {
		/* printf("ra: %d  rra: %d  pb: %d rb: %d rrb: %d rr: %d rrr: %d\n", current->ra, current->rra, current->pb, current->rb, current->rrb, current->rr, current->rrr);
		printf("coste: %d\n", current->costo); */
		current = current->next;
	}
	/* printf("\n"); */
}

void check_max_min(t_stack_a *stack_a)
{
    if (stack_a == NULL) {
        return; // Si el stack está vacío, no hay nada que hacer
    }

    int max = stack_a->num;
    int min = stack_a->num;
    t_stack_a *current = stack_a;

    // Encuentra el valor máximo y mínimo en el stack
    while (current != NULL) {
        if (current->num > max) {
            max = current->num;
        }
        if (current->num < min) {
            min = current->num;
        }
        current = current->next;
    }

    // Actualiza el campo max_min de cada elemento en el stack
    current = stack_a;
    while (current != NULL) {
        if (current->num == max) {
            current->max_three = 1; // El número es el mayor
        } else if (current->num == min) {
            current->max_three = 2; // El número es el menor
        } else {
            current->max_three = 0; // El número está entre los dos
        }
        current = current->next;
    }
}

int find_position_for_first_node_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
    t_stack_a *current;
    int position = 0;

    // Encuentra la posición correcta para el primer nodo de stack_b
    current = stack_a;
	/* printf("antes de entrar\na_num=%d num_b=%d\n", current->num, stack_b->num); */
	while(1)
	{
		if (current->num > stack_b->num)
			ra(stack_a);
		else
		{	
			while (current != NULL && current->num < stack_b->num)
			{
			/* printf("a_num=%d num_b=%d\n", current->num, stack_b->num); */
			position++;
			current = current->next;
			}
			return position;
		}
	} 
}

void move_smallest_to_top(t_stack_a *stack_a)
{
    int i;
	t_stack_a *current;
	
	current = stack_a;
	i = 0;
	check_max_min(stack_a);
	while(current->max_three != 2)
	{
		i ++;
		current = current->next;
	}
	while (i >= 0)
	{
		rra(stack_a);
		i --;
	}
}

void wallet_algorithm(t_stack_a *stack_a, t_stack_b *stack_b, int cant_nodes)
{
	int i;
	int middle;
	int position;
	t_stack_a  *aux_a;
	(void) cant_nodes;

	if (stack_a->num > stack_a->next->num)
		sa(stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	aux_a = stack_a;
	cant_nodes = count_nodes(stack_a);
	while (cant_nodes > 3)
	{
		i = 0;
		cant_nodes = count_nodes(stack_a);
		middle = (cant_nodes / 2);
		while (i < cant_nodes && cant_nodes > 3)
		{
			if (i <= middle)
				aux_a->ra = i;
			else
				aux_a->rra = cant_nodes - i;
			aux_a->pb = 1;
			movement_for_order(aux_a, stack_b);	
			i ++;
			aux_a = aux_a->next;
			cant_nodes = count_nodes(stack_a);
		}
		count_costo_a(stack_a);
		node_to_move_tob_b(&stack_a, &stack_b);
		cant_nodes = count_nodes(stack_a);
		aux_a = stack_a;
	}
	order_three_w(&stack_a);

	while (stack_b != NULL)
    {
        // Encuentra la posición correcta para el primer nodo de stack_b en stack_a ordenado
        position = find_position_for_first_node_b(stack_a, stack_b);
        /* printf("La posición correcta para el primer nodo de stack_b en stack_a ordenado es: %d\n", position);
		printf("A\n");
   		print_list(stack_a);
		printf("B\n");
    	print_list_b(stack_b); */

        // Mueve los elementos de stack_a hacia adelante hasta la posición correcta
        int i = 0;
        while (i < position && stack_a != NULL) {
            ra(&stack_a); // Mueve el primer elemento de stack_a al final
            i++;
        }
        // Inserta el primer nodo de stack_b en la posición correcta
        if (stack_a != NULL) {
            pa(&stack_a, &stack_b);
        }
    }
	move_smallest_to_top(stack_a);
	/* write(1, "transfer_sorted_from_b_to_a\n", 28); */
	/* transfer_sorted_from_b_to_a(&stack_a, &stack_b); */
	
	//terminamos con los movimientoos
	printf("final\n");
	print_movement(stack_a);
	printf("A\n");
	print_list(stack_a);
	printf("B\n");
	print_list_b(stack_b);
	exit (0);
}
