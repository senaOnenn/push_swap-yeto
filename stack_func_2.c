/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:07:17 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 15:25:43 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*last;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	previous = NULL;
	last = *stack;
	while (last->next) // listnein sonuna git, prev sondan bir önceki olcak
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;   // sondan bir öncekinin bağını koparıp
	last->next = *stack; // son elemanı başa alıyoruz
	*stack = last;       // stack başını son eleman olarak güncelle
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n",4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n",4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n",4);
}
