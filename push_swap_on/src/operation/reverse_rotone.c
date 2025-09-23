#include "../../includes/push_swap.h"

static void reverse_rotate_stack(t_node **stack) {
    t_node *current;
    t_node *prev;
    
    if (!*stack || !(*stack)->next)
        return;
    
    current = *stack;
    prev = NULL;
    
    while (current->next) {
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

void rra(t_stacks *stacks) {
    reverse_rotate_stack(&stacks->a);
    ft_putendl_fd("rra", 1);
}

void rrb(t_stacks *stacks) {
    reverse_rotate_stack(&stacks->b);
    ft_putendl_fd("rrb", 1);
}

void rrr(t_stacks *stacks) {
    reverse_rotate_stack(&stacks->a);
    reverse_rotate_stack(&stacks->b);
    ft_putendl_fd("rrr", 1);
}
