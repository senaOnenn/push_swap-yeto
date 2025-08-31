/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:54 by eonen             #+#    #+#             */
/*   Updated: 2025/08/30 18:24:58 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"


int main(int argc, char **argv)
{
    t_stack *a ;
    t_stack *b ;
    char    **nums;
    int     is_split;
    int     i;

	a = NULL;
	b = NULL;
    if (argc < 2)
        return (0);

    is_split = 0;
    if (argc == 2)
    {
        nums = ft_split(argv[1], ' ');
        if (!nums)
            return (1);
        is_split = 1;
    }
    else
        nums = &argv[1];

    i = 0;
    while (nums[i])
    {
        if (!is_valid(nums[i]) || has_dup(a, ft_atol(nums[i])))
        {
            write(2, "Error\n", 6);
            free_stack(&a);
            if (is_split)
                full_free_arr(nums);
            return (1);
        }
        add_back(&a, new_node(ft_atol(nums[i])));
        i++;
    }
    if (is_split)
        full_free_arr(nums);

    // indeksleri ata
    set_index(a);

    // Eğer zaten sıralı değilse sıralama yap
    if (!is_sorted(a))
    {
        if (stack_size(a) == 2)
            sa(&a);
        else if (stack_size(a) == 3)
            three_sorting(&a);
        else
            big_sorting(&a, &b); // burada move ve move_a_to_b kullanılacak
    }

    free_stack(&a);
    free_stack(&b);
    return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    char line[10000]; // Tek satırda çok sayıda sayı için buffer
    char **nums;
    int i;

    FILE *fp = fopen("numbers.txt", "r");
    if (!fp)
    {
        write(2, "Error: Cannot open numbers.txt\n", 31);
        return 1;
    }

    if (!fgets(line, sizeof(line), fp))
    {
        write(2, "Error: Empty file\n", 18);
        fclose(fp);
        return 1;
    }
    fclose(fp);

    nums = ft_split(line, ' ');
    if (!nums)
        return 1;

    // Argümanları kontrol et ve A yığınına ekle
    i = 0;
    while (nums[i])
    {
        if (!is_valid(nums[i]) || has_dup(a, ft_atol(nums[i])))
        {
            write(2, "Error\n", 6);
            free_stack(&a);
            full_free_arr(nums);
            return 1;
        }
        add_back(&a, new_node(ft_atol(nums[i])));
        i++;
    }

    full_free_arr(nums);
    // Yığın boyutunu hesapla ve indeksleri ata
    set_index(a);

    // Eğer yığın zaten sıralıysa çık
    if (!is_sorted(a))
    {
        if (stack_size(a) <= 3)
        {
            if (stack_size(a) == 2)
                sa(&a);
            else
                three_sorting(&a);
        }
        else
            big_sorting(&a, &b);
    }

    // Yığınları temizle
    free_stack(&a);
    free_stack(&b);
    return 0;
}
*/