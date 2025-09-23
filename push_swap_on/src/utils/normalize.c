#include "../../includes/push_swap.h"

void normalize_stack(t_stacks *stacks)
{
    t_node *current;
    t_node *compare;
    int index;

    current = stacks->a;
    while (current) {
        index = 0;
        compare = stacks->a;
        while (compare) {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

int is_sorted(t_node *stack) 
{
    while (stack && stack->next) 
    {
        if (stack->index > stack->next->index)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int has_duplicates(t_node *stack) 
{
    t_node *current = stack;
    
    while (current) 
    {
        t_node *compare = current->next;
        while (compare) 
        {
            if (current->value == compare->value)
                return 1;
            compare = compare->next;
        }
        current = current->next;
    }
    return 0;
}