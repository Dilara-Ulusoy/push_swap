/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:28:10 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:28:13 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sort_three(t_stack_node **a)
{
    int first = (*a)->data;
    int second = (*a)->next->data;
    int third = (*a)->next->next->data;

    if (first > second && second < third && first < third) // 2 1 3 -> 1 2 3
    {
        sa(a);
    }
    else if (first > second && second > third && first > third) // 3 2 1 -> 1 2 3
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third) // 3 1 2 -> 2 3 1
    {
        ra(a);
    }
    else if (first < second && second > third && first < third) // 1 3 2 -> 1 2 3
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third) // 2 3 1 -> 3 1 2
    {
        rra(a);
    }
}
void sort_four(t_stack_node **a, t_stack_node **b)
{
    if(stack_len(a) != 4)
        return;
    
    find_max_and_carry_to_top(a);
    pb(b, a);
    sort_three(a);
    pa(a, b);
    ra(a);
}
void sort_five(t_stack_node **a, t_stack_node **b)
{
    if (stack_len(a) != 5)
        return;
    
    find_max_and_carry_to_top(a);
    pb(b, a);
    sort_four(a, b);
    pa(a, b);
    ra(a);

}
void sort_big(t_stack_node **a, t_stack_node **b)
{
    if (a == NULL || b == NULL || *a == NULL)
        return;

    int size = stack_len(a);
  
    while (size > 3)
    {
        pb(b, a);
        size--;
    }
    sort_three(a);
    while (stack_len(b) > 0)
    {
        init_stacks(a, b);
        move_cheapest_of_b_to_a(a, b);
    }
    while(is_sorted(a) == 0)
    {
        ra(a);
    }
}