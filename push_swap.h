/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:16:00 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/03 22:16:03 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "push_swap.h"
#include "Libft/libft.h"
#include "Printf/ft_printf.h"


typedef struct s_stack_node
{
    int data;
    struct s_stack_node *next;
    struct s_stack_node *prev;
    int push_price;
    int steps_to_top;
    int index;
    bool cheapest;
    bool is_index_before_center;
    struct s_stack_node *target_node;

} t_stack_node;


// Stack functions
int     stack_len(t_stack_node **stack);
void    add_to_stack(t_stack_node **head, int num);
void    free_stack(t_stack_node **stack); //stack'i free eder
void    print_list(t_stack_node *stack, const char *name);
t_stack_node    **init_stack(void);

// Operations
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void    ss(t_stack_node **a, t_stack_node **b);

void    pb(t_stack_node **b, t_stack_node **a);
void    pa(t_stack_node **a, t_stack_node **b);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);

void    rra(t_stack_node **a); //rra: reverse rotate a
void    rrb(t_stack_node **b); //rrb: reverse rotate b
void    rrr(t_stack_node **a, t_stack_node **b); // rra ve rrb at the same time

//void    parse_input(t_stack_node **a, int argc, char **argv); //girilen argümanları parse eder
void parse_single_arg(t_stack_node **head, char *arg);
void parse_multiple_args(t_stack_node **head, int argc, char **argv);
void parse_input(t_stack_node **head, int argc, char **argv);

//Error handling and checker functions
int     is_number(char *str);
int     is_sorted(t_stack_node **stack);
int     is_duplicate(t_stack_node *head);
void    error_exit(const char *message);

// Short sorting algorithm functions
void sort_three(t_stack_node **a);
void sort_four(t_stack_node **a, t_stack_node **b);
void sort_five(t_stack_node **a, t_stack_node **b);
void find_max_and_carry_to_top(t_stack_node **a);
int find_max_stack_value(t_stack_node *a);
int find_min_stack_value(t_stack_node *a);

//Big  sorting algorithm functions
void push_swap(t_stack_node **a, t_stack_node **b);
void sort_big(t_stack_node **a, t_stack_node **b);
void init_stacks(t_stack_node **a, t_stack_node **b);
void initialize_a_stack(t_stack_node **a);
void initialize_b_stack(t_stack_node **b, t_stack_node *a_head);

// Set functions
void set_steps_to_top(t_stack_node **stack);
void set_target_node(t_stack_node **b);
void set_price(t_stack_node **a, t_stack_node **b);
void set_cheapest_in_b(t_stack_node **b);
void calculate_prices(t_stack_node **b);

void move_cheapest_of_b_to_a(t_stack_node **a, t_stack_node **b);
void move_together(t_stack_node **a, t_stack_node **b, int *steps_a, int *steps_b, bool is_b_before_center, bool is_a_before_center);
void move_remaining(t_stack_node **a, t_stack_node **b, int steps_a, int steps_b, bool is_b_before_center, bool is_a_before_center);
t_stack_node* find_cheapest_node(t_stack_node *b); 
t_stack_node *find_target_node(t_stack_node *a, int value);

  


//Helper functions
int     ft_atol(const char *str);
#endif


