#include "../../includes/push_swap.h"

static int is_valid_number(char *str) {
    int i = 0;
    
    if (!str || !*str)
        return 0;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    
    if (!str[i])
        return 0;
    
    while (str[i]) {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

static int add_number_to_stack(char *str, t_stacks *stacks) {
    long num;
    
    if (!is_valid_number(str))
        return 0;
    
    num = ft_atoi(str);
    if (num < INT_MIN || num > INT_MAX)
        return 0;
    
    add_back(&stacks->a, new_node((int)num));
    stacks->size_a++;
    return 1;
}

static int parse_single_argument(char *arg, t_stacks *stacks) {
    char **split_args;
    int i;
    int success = 1;
    
    split_args = ft_split(arg, ' ');
    if (!split_args)
        return 0;
    
    i = 0;
    while (split_args[i] && success) {
        if (!add_number_to_stack(split_args[i], stacks))
            success = 0;
        i++;
    }
    
    // Free split_args
    i = 0;
    while (split_args[i])
        free(split_args[i++]);
    free(split_args);
    
    return success;
}

int parse_arguments(int argc, char **argv, t_stacks *stacks) {
    int i;
    
    if (argc == 2) {
        return parse_single_argument(argv[1], stacks);
    }
    
    i = 1;
    while (i < argc) {
        if (!add_number_to_stack(argv[i], stacks))
            return 0;
        i++;
    }
    return 1;
}
