#include "push_swap.h"
#include "Libft/libft.h"

int is_number(char *str) {
    if (*str == '-' || *str == '+') {  // Allow negative 
        str++;
    }
    if (*str == '\0') { // String is just "-" or "+"
        return 0;
    }
    while (*str) {
        if (!ft_isdigit((unsigned char)*str)) { 
            return 0;
        }
        str++;
    }
    return 1;
}

int is_duplicate(t_stack_node *head) { // Check for duplicates
    t_stack_node *temp = head;
    while (temp != NULL) {
        t_stack_node *temp2 = temp->next;
        while (temp2 != NULL) {
            if (temp->data == temp2->data) {
                return 1;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return 0;
}

int is_sorted(t_stack_node **stack) { // Check if stack is sorted
    if (*stack == NULL) {
    return 1; // Consider an empty list as sorted or handle differently based on your requirements.
}
    t_stack_node *temp = *stack;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

void error_exit(const char *message) {
    write(2, "Error: ", 7);
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}