#include "../../includes/push_swap.h"

int calculate_cost_a(t_stacks *stacks, int target_pos) {
    if (target_pos <= stacks->size_a / 2)
        return target_pos;
    else
        return target_pos - stacks->size_a;
}

int calculate_cost_b(t_stacks *stacks, int pos) {
    if (pos <= stacks->size_b / 2)
        return pos;
    else
        return pos - stacks->size_b;
}

int find_target_position(t_stacks *stacks, int value) {
    t_node *current = stacks->a;
    int pos = 0;
    int target_pos = 0;
    int closest_bigger = INT_MAX;
    int closest_pos = 0;

    while (current) {
        if (current->index > value && current->index < closest_bigger) {
            closest_bigger = current->index;
            closest_pos = pos;
        }
        current = current->next;
        pos++;
    }

    if (closest_bigger == INT_MAX) {
        // Encontrar o menor elemento se não há elemento maior
        current = stacks->a;
        pos = 0;
        int min_val = INT_MAX;
        while (current) {
            if (current->index < min_val) {
                min_val = current->index;
                target_pos = pos;
            }
            current = current->next;
            pos++;
        }
    } else {
        target_pos = closest_pos;
    }

    return target_pos;
}
