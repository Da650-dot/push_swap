#include "../../includes/push_swap.h"

static void rotate_stack(t_node **stack) 
{
    t_node *first;
    t_node *current;
    
    if (!*stack || !(*stack)->next)
        return;
    
    first = *stack;
    current = *stack;
    
    *stack = first->next;
    while (current->next)
        current = current->next;
    current->next = first;
    first->next = NULL;
}

void ra(t_stacks *stacks)
{
    rotate_stack(&stacks->a);
    ft_putendl_fd("ra", 1);
}

void rb(t_stacks *stacks) 
{
    rotate_stack(&stacks->b);
    ft_putendl_fd("rb", 1);
}

void rr(t_stacks *stacks) 
{
    rotate_stack(&stacks->a);
    rotate_stack(&stacks->b);
    ft_putendl_fd("rr", 1);
}