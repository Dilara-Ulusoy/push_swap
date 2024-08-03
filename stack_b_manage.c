/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:15:34 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:15:44 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "Libft/libft.h"

void set_cheapest_in_b(t_stack_node **b)
{
    if (b == NULL || *b == NULL) return;

    t_stack_node *tmp = *b;
    t_stack_node *cheapest_node = *b;

    // Tüm düğümlerin 'cheapest' işaretini temizle
    while (tmp)
    {
        tmp->cheapest = false;
        tmp = tmp->next;
    }
    tmp = *b; // tmp'yi yeniden başlat
    while (tmp)
    {
        if (tmp->push_price < cheapest_node->push_price)
            cheapest_node = tmp;
        tmp = tmp->next;
    }
    cheapest_node->cheapest = true;
     //printf("Cheapest node in B: %d\n", cheapest_node->data);
     //printf("Target node of cheapest node in A: %d\n", cheapest_node->target_node->data);
}
// Calculate the push price for each node in stack b.
void calculate_prices(t_stack_node **b)
{
    t_stack_node *current_b = *b;
    while (current_b)
    {
        current_b->push_price = current_b->steps_to_top + current_b->target_node->steps_to_top;
        current_b = current_b->next;
    }
}
// Set the target node for each node in stack b.
void set_target_node(t_stack_node **b)
{
    t_stack_node *tmp = *b;
    while (tmp)
    {
        tmp = tmp->next;
    }
}
t_stack_node* find_cheapest_node(t_stack_node *b)
{
    t_stack_node *tmp = b;
    t_stack_node *cheapest_node = NULL;
    int min_price = INT_MAX;

    while (tmp)
    {
        if (tmp->push_price < min_price)
        {
            min_price = tmp->push_price;
            cheapest_node = tmp;
        }
        tmp = tmp->next;
    }
    return cheapest_node;
}