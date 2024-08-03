/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:24:06 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:24:36 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "Libft/libft.h"
#include <limits.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node **a;
    t_stack_node **b;

    a = NULL;
    b = NULL;

    if (argc < 2)
    {
        error_exit("Error: No arguments provided");
    }
    a = init_stack();
    b = init_stack();
    if (!a || !b)
        error_exit("Error: Memory allocation failed");
    
    parse_input(a, argc, argv);
    if (is_duplicate(*a))
        error_exit("Error: Duplicate numbers in input");
    else if (is_sorted(a))
        error_exit("List is already sorted");
    else
        push_swap(a, b);
    free_stack(a);
    free_stack(b);
    return (0); 
}