/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:16:09 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:16:14 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void push_swap(t_stack_node **a, t_stack_node **b)
{
    int len;

    len = stack_len(a);
    if (len == 2)
        sa(a);
    else if (len == 3)
        sort_three(a);
    else if (len == 4)
        sort_four(a, b);
    else if (len == 5)
        sort_five(a, b);
    else if (len > 5)
        sort_big(a, b);
    else
    {
        ft_printf("Error: Invalid stack length\n");
        return;
    }
}
void find_max_and_carry_to_top(t_stack_node **a) 
{
    if (!(*a) || !((*a)->next)) return;  // Eğer liste boşsa veya tek eleman varsa işlem yapmaya gerek yok.

    t_stack_node *max = *a; 
    t_stack_node *tmp = (*a)->next;  // Başlangıçtan itibaren karşılaştırmaya başla.

    while (tmp) {
        if (tmp->data > max->data) {
            max = tmp;  // Yeni maksimum bulundu.
        }
        tmp = tmp->next;  // Sonraki elemana geç.
    }
    // Bulunan maksimum elemanı yığının başına al.

    if (max == *a) {
        return;  // Maksimum zaten başta.
    }
    else if (max->next == NULL) {
        rra(a);  // Maksimum en sondaysa sondan başa al.
    }
    else {
        while ((*a) != max) {
            ra(a);  // Maksimum en başa gelene kadar döndür.
        }
    }
}

int find_min_stack_value(t_stack_node *a){

    int i = 0;
    i = a -> data; 
    while (a)
    {
        if (a->data < i) 
        {
            i = a->data;
        }
        a = a->next;
    }
    return i; 
}

int find_max_stack_value(t_stack_node *a) 
{
    int i = 0;
    i = a -> data;
    while (a)
    {
        if (a->data > i)
        {
            i = a->data;
        }
        a = a->next;
    }
    return i;
}

