#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node {
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stacks {
    t_node *a;
    t_node *b;
    int size_a;
    int size_b;
} t_stacks;

// Main functions
void push_swap(t_stacks *stacks);

// Operations
void sa(t_stacks *stacks);
void sb(t_stacks *stacks);
void ss(t_stacks *stacks);
void pa(t_stacks *stacks);
void pb(t_stacks *stacks);
void ra(t_stacks *stacks);
void rb(t_stacks *stacks);
void rr(t_stacks *stacks);
void rra(t_stacks *stacks);
void rrb(t_stacks *stacks);
void rrr(t_stacks *stacks);

// Algorithms
void sort_three(t_stacks *stacks);
void sort_four(t_stacks *stacks);
void sort_five(t_stacks *stacks);
void sort_small(t_stacks *stacks);
void turk_algorithm(t_stacks *stacks);

// Cost calculation
int calculate_cost_a(t_stacks *stacks, int target_pos);
int calculate_cost_b(t_stacks *stacks, int pos);
int find_target_position(t_stacks *stacks, int value);

// Utils
int is_sorted(t_node *stack);
int has_duplicates(t_node *stack);
void normalize_stack(t_stacks *stacks);
int parse_arguments(int argc, char **argv, t_stacks *stacks);
void error_exit(void);

// Stack utils
t_node *new_node(int value);
void add_back(t_node **stack, t_node *new);
void free_stack(t_node *stack);
int find_position_by_index(t_node *stack, int target_index);
int find_min_index(t_node *stack);

#endif
