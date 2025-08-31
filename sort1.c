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
    if (!a)
        return 0;
    t_stack *cur = a;
    int min = find_min_index(a);
    int max = find_max_index(a);
    int pos = 0;

    if (index_b < min || index_b > max)
        return find_position(a, min);

    while (cur->next)
    {
        if (index_b > cur->index && index_b < cur->next->index)
            return pos + 1;
        cur = cur->next;
		 pos++;
    }
    return pos+1;;
}

void three_sorting(t_stack **a)
{
    if (!a || stack_size(*a) != 3)
        return;
    t_stack *first = *a;
    t_stack *second = first->next;
    t_stack *third = second->next;

    if (first->index < second->index && second->index < third->index)
        return;
    else if (first->index > second->index && first->index < third->index)
        sa(a);
    else if (first->index > second->index && second->index < third->index && first->index > third->index)
        ra(a);
    else if (first->index < second->index && second->index > third->index && first->index < third->index)
    {
        sa(a);
        ra(a);
    }
    else if (first->index < second->index && second->index > third->index && first->index > third->index)
        rra(a);
    else if (first->index > second->index && second->index > third->index)
    {
        sa(a);
        rra(a);
    }
}

void big_sorting(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    int pos, size;

    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return;

    // 1️⃣ A’dan B’ye 3 eleman kalana kadar en ucuz node’u gönder
    while (stack_size(*a) > 3)
    {
        calculate_cost_a_to_b(*a, *b);
        cheapest = find_cheapest_to_push(*a);
        move_a_to_b(a, b, cheapest);
    }

    // 2️⃣ A’da kalan 3 elemanı sırala
    three_sorting(a);

    // 3️⃣ B’deki elemanları A’ya geri taşırken maliyet hesapla
    while (*b)
    {
        calculate_cost_b_to_a(*a, *b);
        cheapest = cheapest_action(*b);
        if (!cheapest)
            break;
        move(a, b, cheapest);
    }

    // 4️⃣ En küçük index’i başa getir
    pos = find_position(*a, 0);
    size = stack_size(*a);
    while (pos > 0)
    {
        if (pos <= size / 2)
            ra(a);
        else
            rra(a);
        pos = find_position(*a, 0);
    }
	sort_stack_a(a);
}



void calculate_cost_b_to_a(t_stack *a, t_stack *b)
{
    t_stack *tmp = b;
    int size_a = stack_size(a);
    int size_b = stack_size(b);

    while (tmp)
    {
        int pos_a = find_target_pos_a(a, tmp->index);
        int pos_b = find_position(b, tmp->index);

        tmp->cost_a = (pos_a <= size_a / 2) ? pos_a : pos_a - size_a;
        tmp->cost_b = (pos_b <= size_b / 2) ? pos_b : pos_b - size_b;

        if ((tmp->cost_a >= 0 && tmp->cost_b >= 0) || (tmp->cost_a < 0 && tmp->cost_b < 0))
            tmp->total_cost = ft_abs(tmp->cost_a) > ft_abs(tmp->cost_b) ? ft_abs(tmp->cost_a) : ft_abs(tmp->cost_b);
        else
            tmp->total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);

        tmp = tmp->next;
    }
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

t_stack *cheapest_action(t_stack *b)
{
    if (!b)
        return NULL;

    t_stack *tmp = b;
    t_stack *lowest = b;
    int min = b->total_cost;

    while (tmp)
    {
        if (tmp->total_cost < min)
        {
            min = tmp->total_cost;
            lowest = tmp;
        }
        tmp = tmp->next;
    }

    return lowest;
}
