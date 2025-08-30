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

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	set_index(t_stack *a, int size)
{
	t_stack	*current;
	int		i;

	(void)size;
	while (a)
	{
		i = 0;
		current = a;
		while (current)
		{
			if (a->value > current->value)
				i++;
			current = current->next;
		}
		a->index = i;
		a = a->next;
	}
}


int	find_min_index(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	find_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
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
