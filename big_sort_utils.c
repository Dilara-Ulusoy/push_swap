/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:14:59 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:15:06 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "Libft/libft.h"

// Find the target node for the given value in the stack a. 
// The target node is the first node with a value greater than the given value. 
// If no such node is found, return the head of the stack.
t_stack_node *find_target_node(t_stack_node *a, int value)
{
    t_stack_node *tmp = a;
    t_stack_node *target = NULL;

    while (tmp)  // A yığınında gezerek target node'u bul
    {
        if (tmp->data > value) //Value burada b stackindeki bir elemanin degeri
        {
            if (target == NULL || tmp->data < target->data)
                target = tmp;
        }
        tmp = tmp->next;
    }
    if (target == NULL)  // Eğer target NULL kaldıysa, A yığındaki en küçük düğümü hedef olarak belirle
    {
        tmp = a;
        target = tmp;
        while (tmp)
        {
            if (tmp->data < target->data)
                target = tmp;
            tmp = tmp->next;
        }
    }
    return target;
}

void move_cheapest_of_b_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node = find_cheapest_node(*b);
    if (cheapest_node == NULL)
        return;

    int steps_b = cheapest_node->steps_to_top; 
    int steps_a = cheapest_node->target_node->steps_to_top;

    // If the cheapest node is not at the top of the stack, move it to the top
    if (cheapest_node->target_node != *a)
    {
        move_together(a, b, &steps_a, &steps_b, cheapest_node->is_index_before_center, cheapest_node->target_node->is_index_before_center);
        move_remaining(a, b, steps_a, steps_b, cheapest_node->is_index_before_center, cheapest_node->target_node->is_index_before_center);
    }
    else
    {
        while (steps_b > 0)  // Before moving the cheapest node to A, move the other nodes in B to the top
        {
            if (cheapest_node->is_index_before_center)
                rb(b); // Move up
            else
                rrb(b); // Move down
            steps_b--;
        }
    }
    pa(a, b);// Move stack B to A
}

void move_together(t_stack_node **a, t_stack_node **b, int *steps_a, int *steps_b, bool is_b_before_center, bool is_a_before_center)
{
    // Yukarı doğru hareket (rr) için
    if (is_b_before_center && is_a_before_center)
    {
        while (*steps_a > 0 && *steps_b > 0)
        {
            rr(a, b);
            (*steps_a)--;
            (*steps_b)--;
        }
    }
    // Aşağı doğru hareket (rrr) için
    else if (!is_b_before_center && !is_a_before_center)
    {
        while (*steps_a > 0 && *steps_b > 0)
        {
            rrr(a, b);
            (*steps_a)--;
            (*steps_b)--;
        }
    }
}

void move_remaining(t_stack_node **a, t_stack_node **b, int steps_a, int steps_b, bool is_b_before_center, bool is_a_before_center)
{
    // Turn only the A stack
    while(steps_a > 0)
    {
        if (is_a_before_center)
            ra(a); // Move up
        else
            rra(a); // Move down
        steps_a--;
    }
    // Turn only the B stack
    while (steps_b > 0) 
    {
        if (is_b_before_center)
            rb(b); // Move up
        else
            rrb(b); // Move down
        steps_b--;
    }
}



