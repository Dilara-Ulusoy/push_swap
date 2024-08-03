#include "push_swap.h"
#include "Libft/libft.h"

void init_stacks(t_stack_node **a, t_stack_node **b)
{
    if (a == NULL || b == NULL)
        return;

    initialize_a_stack(a);
    initialize_b_stack(b, *a);
    calculate_prices(b);
    set_cheapest_in_b(b);
}

// This function initializes the stack a. It sets the index, is_index_before_center, and steps_to_top for each node.
void initialize_a_stack(t_stack_node **a)
{
    int index = 0;
    int len_a = stack_len(a);
    int center;
     if (len_a % 2 == 0) //If the stack has an even number of elements, the center is the middle two elements.
    {
        center = len_a / 2; 
    }
    else //If the stack has an odd number of elements, then the center is the middle element.
    {
        center = (len_a + 1) / 2; 
    }

    t_stack_node *current_a = *a;

   while (current_a)
    {
        current_a->index = index;
        current_a->is_index_before_center = (index < center);
        
        // calculate the number of steps to the top of the stack
        if (index < center)
        {
            current_a->steps_to_top = index;
        }
        else
        {
            current_a->steps_to_top = len_a - index;
        }

        current_a = current_a->next;
        index++;
    }
}

// This function initializes the stack b. It sets the target node, index, is_index_before_center, and steps_to_top for each node.
void initialize_b_stack(t_stack_node **b, t_stack_node *a_head)
{
    int index = 0;
    int len_b = stack_len(b);
    int center_index_b = len_b / 2;
    t_stack_node *current_b = *b;

    while (current_b)
    {
        current_b->target_node = find_target_node(a_head, current_b->data);
        current_b->index = index;
        current_b->is_index_before_center = (index < center_index_b);
        // calculate the number of steps to the top of the stack
        if (index < center_index_b)
        {
            current_b->steps_to_top = index;
        }
        else
        {
            current_b->steps_to_top = len_b - index;
        }
        current_b = current_b->next;
        index++;
    }
}

