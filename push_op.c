/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:22:25 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:22:28 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void pb(t_stack_node **b, t_stack_node **a) // pb - push b. Take the first element at the top of a and put it at the top of b
{
    if(*a == NULL) // If the current stack is empty,
        return;
    t_stack_node *tmp = *b;
    *b = *a;
    *a = (*a)->next;
    (*b)->next = tmp;
    write(1, "pb\n", 3);

}

void pa(t_stack_node **a, t_stack_node **b) // pa - push a. Take the first element at the top of b and put it at the top of a
{
    if(*b == NULL)
        return;
    t_stack_node *tmp = *a;
    *a = *b;
    *b = (*b)->next;
    (*a)->next = tmp;
    write(1, "pa\n", 3);

}

void ra(t_stack_node **a) // ra - rotate a - shift up all elements of stack a by 1. The first element becomes the last one
{
    if (*a == NULL || (*a)->next == NULL || stack_len(a) == 1)
        return;
    t_stack_node *tmp = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    t_stack_node *last = *a;
    while (last->next != NULL)
        last = last->next; //
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
    write(1, "ra\n", 3);
}


