/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:32:18 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 16:39:08 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int find_target_pos_a(t_stack *a, int index_b)
{
	int position;
	t_stack *current;
	int min_index_a;
	int max_index_a;
	
	position = 0;
	current = a;
	min_index_a = find_min_index(a);
	max_index_a = find_max_index(a);
	
	if(index_b > max_index_a || index_b < min_index_a)
		return (find_position(a, min_index_a));
	while(current)
	{
		if (index_b > current->index && index_b < current->next->index)
			return (position + 1);
		position++;
		current = current->next;
	}
	return(-1);
}

void	three_sorting(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || !*a || !(*a)->next)
		return ;
	first = (*a);
	second = first->next;
	third = second->next;
	if (!third) // sadece 2 eleman var
	{
		if (first->index > second->index)
			sa(a);
		return ;
	}
	if (first->index > second->index && first->index < third->index && second->index < third->index)
    {
        sa(a);
    }
    else if (first->index > second->index && second->index > third->index)
    {
        sa(a);
        rra(a);
    }
    else if (first->index > second->index && first->index > third->index && second->index < third->index)
    {
        ra(a);
    }
    else if (first->index < second->index && first->index < third->index && second->index > third->index)
    {
        sa(a);
        ra(a);
    }
    else if (first->index < second->index && first->index > third->index && second->index > third->index)
    {
        rra(a);
    }
}

void	big_sorting(t_stack **a, t_stack **b)
{
	t_stack	*lowest;
	int min_index;
	int position;
	int size;
	
	while (stack_size(*a) > 3)
	{
		min_index = find_min_index(*a);
		
		while((*a)->index != min_index)
		{
			position = find_position(*a, min_index);
			size = stack_size(*a);
			if(position <= size /2)
				ra(a);
			else
				rra(a);
		}
		pb(a,b);
	}
	three_sorting(a);
	while (*b)
	{
		calculate_cost(*a, *b);
		lowest = cheapest_action(*b);
		move(a, b, lowest);
	}
	sort_stack_a(a);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	int		position_a;
	int		position_b;
	int		size_a;
	int		size_b;
	int		cost_a_abs;
	int		cost_b_abs;

	temp = b;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (temp)
	{
		position_a = find_target_pos_a(a, temp->index);
		if (position_a <= size_a / 2)
			temp->cost_a = position_a;
		else
			temp->cost_a = position_a - size_a;
		position_b = find_position(b, temp->index);
		if (position_b <= size_b / 2)
			temp->cost_b = position_b;
		else
			temp->cost_b = position_b - size_b;
		cost_a_abs = ft_abs(temp->cost_a);
		cost_b_abs = ft_abs(temp->cost_b);
		if ((temp->cost_a >= 0 && temp->cost_b >= 0) || (temp->cost_a <= 0
				&& temp->cost_b <= 0))
		{
			if (cost_a_abs > cost_b_abs)
				temp->total_cost = cost_a_abs;
			else
				temp->total_cost = cost_b_abs;
		}
		else
			temp->total_cost = cost_a_abs + cost_b_abs;
		temp = temp->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

t_stack	*cheapest_action(t_stack *b)
{
	t_stack	*temp;
	t_stack	*lowest;
	int		min;
	int		total;

	temp = b;
	lowest = b;
	min = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
	while (temp)
	{
		total = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
		if (total < min)
		{
			min = total;
			lowest = temp;
		}
		temp = temp->next;
	}
	return (lowest);
}
