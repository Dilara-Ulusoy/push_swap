/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:22:52 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:22:55 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb(t_stack_node **b) // rb - rotate b
{
    if (*b == NULL || (*b)->next == NULL || stack_len(b) == 1)
        return;
    t_stack_node *tmp = *b;
    *b = (*b)->next;
    (*b)->prev = NULL;
    t_stack_node *last = *b;
    while (last->next != NULL)
        last = last->next;
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
    write(1, "rb\n", 3);

}

void rr(t_stack_node **a, t_stack_node **b) // rr - ra and rb at the same time
{
    ra(a); // rotate a
    rb(b); // rotate b;
 
}

void rra(t_stack_node **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;

    t_stack_node *last = *a;
    t_stack_node *tmp = NULL; // Son elemanın bir önceki elemanını tutacak geçici bir pointer

    // Son elemana kadar git ve sondan bir önceki elemanı bul
    while (last->next != NULL) {
        tmp = last;  // Son elemandan önceki elemanı güncelle
        last = last->next;      // Son elemana ilerle
    }
    if (tmp) { 
        tmp->next = NULL; // Sondan bir önceki elemanın next'ini null yaparak son elemanı listeden çıkar
    }
    last->next = *a;         // Son elemanı listenin başına ekle
    (*a)->prev = last;       // Eski başlangıç elemanının prev'ini yeni başlangıç elemanına işaret ettir
    last->prev = NULL;       // Yeni başlangıç elemanının prev'ini null yap
    *a = last;               // Başlangıç pointer'ını güncelle
    write(1, "rra\n", 4);

}


void rrb(t_stack_node **b) // rrb - reverse rotate b
{
    if (*b == NULL || (*b)->next == NULL)
        return;
    t_stack_node *last = *b;
    t_stack_node *tmp = NULL;
    while (last->next != NULL) {
        tmp = last;
        last = last->next;
    }
    if (tmp) {
        tmp->next = NULL;
    }
    last->next = *b;
    (*b)->prev = last;
    last->prev = NULL;
    *b = last;
    write(1, "rrb\n", 4);

}

void rrr (t_stack_node **a, t_stack_node **b) // rrr - rra and rrb at the same time
{
    rra(a); // reverse rotate a
    rrb(b); // reverse rotate b

}  
