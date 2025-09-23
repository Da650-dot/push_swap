include "../../includes/push_swap.h"

t_node *new_node(int value) 
{
    t_node *node = ft_calloc(1, sizeof(t_node));
    if (!node) 
        exit(1);
    
    node->value = value;
    node->index = 0;
    node->next = NULL;
    return node;
}

void add_back(t_node **stack, t_node *new) 
{
    t_node *current;
    
    if (!*stack) 
    {
        *stack = new;
        return;
    }
    
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new;
}

void free_stack(t_node *stack) 
{
    t_node *temp;
    
    while (stack) 
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int find_position_by_index(t_node *stack, int target_index) 
{
    int pos = 0;
    
    while (stack)
    {
        if (stack->index == target_index)
            return pos;
        stack = stack->next;
        pos++;
    }
    return -1;
}

int find_min_index(t_node *stack) 
{
    int min = INT_MAX;
    
    while (stack) 
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return min;
}