#include "../../includes/push_swap.h"

static void swap_stack(t_node **stack)
 {
    t_node *first;
    t_node *second;
    int temp_value;
    int temp_index;
    
    if (!*stack || !(*stack)->next)
        return;
    
    first = *stack;
    second = first->next;
    
    temp_value = first->value;
    temp_index = first->index;
    first->value = second->value;
    first->index = second->index;
    second->value = temp_value;
    second->index = temp_index;
}

void sa(t_stacks *stacks)
{
    swap_stack(&stacks->a);
    ft_putendl_fd("sa", 1);
}

void sb(t_stacks *stacks) 
{
    swap_stack(&stacks->b);
    ft_putendl_fd("sb", 1);
}

void ss(t_stacks *stacks) 
{
    swap_stack(&stacks->a);
    swap_stack(&stacks->b);
    ft_putendl_fd("ss", 1);
}