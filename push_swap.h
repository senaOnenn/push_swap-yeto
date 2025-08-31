/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:45:23 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 17:28:47 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;       // Node değeri
	int				index;       // Sıralama için index
	int				cost_a;      // A yığınına taşımak için maliyet
	int				cost_b;      // B yığınına taşımak için maliyet
	int				total_cost;  // Toplam maliyet (rr/rrr optimizasyonu dahil)
	struct s_stack	*next;       // Linked list pointer
} t_stack;


int					is_digit(int c);
int					is_valid(char *str);
long				ft_atol(const char *nptr);
void				free_stack(t_stack **stack);
int					is_sorted(t_stack *stack);
int					has_dup(t_stack *a, int new_value);
void				full_free_arr(char **array);
t_stack				*new_node(long value);
void				add_back(t_stack **stack_a, t_stack *node);
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				push(t_stack **src, t_stack **dest);
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
int					stack_size(t_stack *stack);
void				set_index(t_stack *a);
int					find_min_index(t_stack *stack);
int					find_max_index(t_stack *stack);
int					find_position(t_stack *stack, int index);
int					find_target_pos_a(t_stack *a, int index_b);
void				three_sorting(t_stack **a);
void				big_sorting(t_stack **a, t_stack **b);
void				calculate_cost_b_to_a(t_stack *a, t_stack *b);
int					ft_abs(int n);
t_stack				*cheapest_action(t_stack *b);
void				move(t_stack **a, t_stack **b, t_stack *node);
void				sort_stack_a(t_stack **a);
int					find_target_pos_b(t_stack *b, int index_a);
void				calculate_cost_a_to_b(t_stack *a, t_stack *b);
t_stack				*find_cheapest_to_push(t_stack *a);
void				move_a_to_b(t_stack **a, t_stack **b, t_stack *cheapest);
void				free_arr(char **array, size_t count);
char				**ft_split(char const *s, char c);

#endif