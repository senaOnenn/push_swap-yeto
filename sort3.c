#include "push_swap.h"


int find_target_pos_b(t_stack *b, int index_a)
{
    if (!b)
        return 0;
    t_stack *cur = b;
    int min = find_min_index(b);
    int max = find_max_index(b);
    int pos = 0;

    if (index_a < min || index_a > max)
        return find_position(b, max);

    while (cur->next)
    {
        if (index_a < cur->index && index_a > cur->next->index)
            return pos + 1;
        cur = cur->next;
		pos++;
    }
    return pos+1;
}

void calculate_cost_a_to_b(t_stack *a, t_stack *b)
{
    t_stack *tmp = a;
    int size_a = stack_size(a);
    int size_b = stack_size(b);

    while (tmp)
    {
        int pos_a = find_position(a, tmp->index);       // A’da mevcut pozisyon
        int pos_b = (b) ? find_target_pos_b(b, tmp->index) : 0; // B’de target pozisyon, B boşsa 0

        tmp->cost_a = (pos_a <= size_a / 2) ? pos_a : pos_a - size_a;
        tmp->cost_b = (pos_b <= size_b / 2) ? pos_b : pos_b - size_b;

        // total_cost hesaplama
        if ((tmp->cost_a >= 0 && tmp->cost_b >= 0) || (tmp->cost_a < 0 && tmp->cost_b < 0))
            tmp->total_cost = ft_abs(tmp->cost_a) > ft_abs(tmp->cost_b) ? ft_abs(tmp->cost_a) : ft_abs(tmp->cost_b);
        else
            tmp->total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);

        tmp = tmp->next;
    }
}


t_stack *find_cheapest_to_push(t_stack *a)
{
	if(!a)
		return NULL;
    t_stack *tmp = a;
    t_stack *cheapest = a;
    int min = a->total_cost;

    while (tmp)
    {
        if (tmp->total_cost < min)
        {
            min = tmp->total_cost;
            cheapest = tmp;
        }
        tmp = tmp->next;
    }
    return cheapest;
}

void move_a_to_b(t_stack **a, t_stack **b, t_stack *node)
{
    if (!a || !b || !node)
        return;

    while (node->cost_a > 0 && node->cost_b > 0)
    {
        rr(a, b);
        node->cost_a--;
        node->cost_b--;
    }

    while (node->cost_a < 0 && node->cost_b < 0)
    {
        rrr(a, b);
        node->cost_a++;
        node->cost_b++;
    }

    while (node->cost_a > 0)
    {
        ra(a);
        node->cost_a--;
    }
    while (node->cost_a < 0)
    {
        rra(a);
        node->cost_a++;
    }

    while (node->cost_b > 0)
    {
        rb(b);
        node->cost_b--;
    }
    while (node->cost_b < 0)
    {
        rrb(b);
        node->cost_b++;
    }

    pb(a, b);
}
