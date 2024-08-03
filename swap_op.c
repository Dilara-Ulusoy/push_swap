/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:22:39 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:22:41 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void sa(t_stack_node **a) // swap a - swap the first 2 elements at the top of stack a
{
    
    if (*a == NULL || (*a)->next == NULL)
        return;
    int tmp = (*a)->data;
    (*a)->data = (*a)->next->data;
    (*a)->next->data = tmp;
    write(1, "sa\n", 3);

}

void sb(t_stack_node **b) // swap b - swap the first 2 elements at the top of stack b
{
    if (*b == NULL || (*b)->next == NULL) //If the current stack is empty or has only one element, return
        return;
    int tmp = (*b)->data;
    (*b)->data = (*b)->next->data;
    (*b)->next->data = tmp;
    write(1, "sb\n", 3);

}

void ss(t_stack_node **a, t_stack_node **b) // ss - sa and sb at the same time
{
    sa(a); // swap a
    sb(b); // swap b

}