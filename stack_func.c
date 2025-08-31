/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:50 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 13:03:33 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(long value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->index = 0;
    node->cost_a = 0;
    node->cost_b = 0;
    node->total_cost = 0;
    node->next = NULL;
    return node;
}

void add_back(t_stack **stack_a, t_stack *node)
{
    t_stack *temp;
    
    if(!*stack_a) //eğer liste boşsa
    {
        *stack_a = node; //yeni eleman direkt başa alınır
        return;
    }
    temp = *stack_a; //tempi listenin başına işaretleriz
    while(temp->next) //listenin sonuna kadar gidilir 
        temp = temp->next;
    temp->next  = node; //son düğümün nextine yeni eleman bağlanır
}

void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    
    if(!*stack || !(*stack)->next)
        return;
    first = *stack; //ilk düğüm
    second =  first->next; //ikinci düğüm
    
    first->next = second->next;//birincinin nextini güncelle
    second->next = first; //ikinciyi öne al
    *stack = second; //stackin başını ikinciye güncelle
}

void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n",3);
}
void sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n",3);
}