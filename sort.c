/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:57:32 by eonen             #+#    #+#             */
/*   Updated: 2025/08/26 19:27:21 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}


void set_index(t_stack *a)
{
    if (!a)
        return;

    t_stack *current = a;
    t_stack *tmp;
    int idx;

    while (current)
    {
        idx = 0;
        tmp = a;
        while (tmp)
        {
            if (current->value > tmp->value)
                idx++;
            tmp = tmp->next;
        }
        current->index = idx;
        current = current->next;
    }
}

int find_min_index(t_stack *stack)
{
    if (!stack)
        return -1;
    int min = stack->index;
    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return min;
}

int find_max_index(t_stack *stack)
{
    if (!stack)
        return -1;
    int max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return max;
}

int	find_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
