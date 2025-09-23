#include "../../includes/push_swap.h"

static void push_stack(t_node **dst, t_node **src) {
    t_node *temp;
    
    if (!*src)
        return;
    
    temp = *src;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
}

void pa(t_stacks *stacks) {
    if (stacks->size_b == 0)
        return;
    
    push_stack(&stacks->a, &stacks->b);
    stacks->size_a++;
    stacks->size_b--;
    ft_putendl_fd("pa", 1);
}

void pb(t_stacks *stacks) {
    if (stacks->size_a == 0)
        return;
    
    push_stack(&stacks->b, &stacks->a);
    stacks->size_b++;
    stacks->size_a--;
    ft_putendl_fd("pb", 1);
}