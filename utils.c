/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:57:36 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 17:24:42 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid(char *str)
{
	int i;
	long number;
	int sign;

	i = 0;
	number = 0;
	sign = 1;
	if (!str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		number = number * 10 + (str[i++] - '0');
		if (sign * number < -2147483648 || sign * number > 2147483647)
			return (0);
	}
	return (1);
}

long ft_atol(const char *nptr)
{
	int	i;
	int	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void free_stack(t_stack **stack)
{
	t_stack *temp;
	
	while(*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int is_sorted(t_stack *stack)
{
	if(!stack)
		return (1);
	while(stack->next)
	{
		if ((stack->value) > (stack->next->value))
			return (0);
		stack = stack->next;
	}
	return(1);
}

int has_dup(t_stack *a, int new_value)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == new_value)
			return (1); // Tekrar eden değer bulundu
		a = a->next;
	}
	return (0); // Tekrar eden değer bulunmadı
}

void full_free_arr(char **array)
{
	int i;
	
	if(!array)
		return;
	i=0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}