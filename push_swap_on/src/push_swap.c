#include "../includes/push_swap.h"

void push_swap(t_stacks *stacks) 
{
    if (is_sorted(stacks->a))
        return;

    if (stacks->size_a == 2) {
        sa(stacks);
    } else if (stacks->size_a == 3) {
        sort_three(stacks);
    } else if (stacks->size_a <= 5) {
        sort_small(stacks);
    } else {
        turk_algorithm(stacks);
    }
}