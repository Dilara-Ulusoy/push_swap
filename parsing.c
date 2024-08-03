/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:31:29 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:32:01 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_single_arg(t_stack_node **head, char *arg) {
    char **temp = ft_split(arg, ' ');
    if (!temp)
        error_exit("Memory allocation failed");

    char **parts = temp;  // Save the original pointer to free it later
    while (*temp) {
        long long num = atol(*temp);
        if (!is_number(*temp) || num > INT_MAX || num < INT_MIN) {
            while (*parts) {  // Free all allocated memory before exiting
                free(*parts);
                parts++;
            }
            free(parts);
            error_exit("Invalid input or number out of range");
        }
        add_to_stack(head, (int)num);
        free(*temp);
        temp++;
    }
    free(parts);  // Free the original array after all elements are freed
}
void parse_multiple_args(t_stack_node **head, int argc, char **argv) {
    int i = 1;  // Start from the second element (index 1) as the first is the program name
    while (i < argc) {
        long long num = atol(argv[i]);
        if (!is_number(argv[i]) || num > INT_MAX || num < INT_MIN) {
            error_exit("Invalid input or number out of range");
        }
        add_to_stack(head, (int)num);
        i++;  // Increment the index for the next iteration
    }
}

void parse_input(t_stack_node **head, int argc, char **argv) {
    if(argc == 1) {
        error_exit("No arguments provided");
    }
    else if (argc == 2) {
        parse_single_arg(head, argv[1]);
    } else if (argc > 2) {
        parse_multiple_args(head, argc, argv);
    } else {
        error_exit("Invalid number of arguments");
    }
}

/*
//In this function, we know that the input is string and we need to convert it to integer.
//We also need to check if the input is a number or not. 
// First we split the input string by space and then we check each element of the array.
// If the element is not a number, we free the allocated memory and exit the program.
// If the element is a number, we convert it to integer and add it to the stack. 
*/