#include "../includes/push_swap.h"

int main(int argc, char **argv) {
    t_stacks stacks = {0};

    if (argc < 2) 
        return 0;

    if (!parse_arguments(argc, argv, &stacks))
        error_exit();

    if (has_duplicates(stacks.a))
        error_exit();

    normalize_stack(&stacks);
    push_swap(&stacks);

    free_stack(stacks.a);
    free_stack(stacks.b);
    return 0;
}