/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:29:41 by manufern          #+#    #+#             */
/*   Updated: 2024/02/03 16:52:42 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void sa(t_stack_a *stack_a)
{
    t_stack_a *aux_stack;
    int aux;
    
    aux_stack = stack_a;
    aux = aux_stack->next->num;
    write(1, "sa\n", 3);
    aux_stack->next->num = aux_stack->num;
    aux_stack->num = aux;
}

void rra(t_stack_a *stack_a)
{
    t_stack_a *aux;
    int num;
    int num_aux;
    
    write(1, "rra\n", 4);
    aux = stack_a;
    num = aux->back->num;
    while (aux != NULL)
    {   
        num_aux = aux->num;
        aux->num = num;
        aux = aux->next;
        num = num_aux;
    }
}

void ra(t_stack_a *stack_a)
{
    t_stack_a *aux;
    int num_aux;
    
    write(1, "ra\n", 3);
    aux = stack_a;
    num_aux =  aux->num;
    while (aux->next != NULL)
    {
        aux->num = aux->next->num;
        aux = aux->next;
    }
    aux->num = num_aux;
}