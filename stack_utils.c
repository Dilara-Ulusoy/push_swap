#include "push_swap.h"
t_stack_node **init_stack(void) // Initialize the stack
{
    t_stack_node **stack; 

    stack = (t_stack_node **)malloc(sizeof(t_stack_node *));
    if (!stack)
        return (NULL);
    *stack = NULL;
    return (stack);
}

void add_to_stack(t_stack_node **head, int num) {
    // Create a new node with the appropriate Libft function or standard allocation
    t_stack_node *new_node = malloc(sizeof(t_stack_node));
    if (!new_node) {
        perror("Failed to allocate memory for a new node");
        exit(EXIT_FAILURE);
    }
    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;  // This might be unnecessary if t_stack_node isn't meant to be used with t_list functions directly

    // Use ft_lstadd_back to add the new node to the end of the list
    ft_lstadd_back((t_list **)head, (t_list *)new_node);
}

int stack_len(t_stack_node **stack) // Calculate the length of the stack
{
    int len = 0;
    t_stack_node *temp = *stack;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return (len);
}

void free_stack(t_stack_node **stack)
{
    t_stack_node *temp;
    while (*stack != NULL)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    free(stack);
}

void print_list(t_stack_node *stack, const char *name) {
    ft_printf("%s: ", name);
    t_stack_node *current = stack;
    while (current != NULL) {
        ft_printf("%d ", current->data);
        current = current->next;
    }
    ft_printf("\n");
}