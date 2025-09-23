#include "../../includes/push_swap.h"

void sort_three(t_stacks *stacks) {
    if (stacks->size_a < 3) 
        return;
    
    int a = stacks->a->index;
    int b = stacks->a->next->index; 
    int c = stacks->a->next->next->index;
    
    // Determinístico - cada caso tem exatamente UMA solução ótima
    if (a == 0 && b == 2 && c == 1)        // [1,3,2]
        sa(stacks);
    else if (a == 1 && b == 0 && c == 2)   // [2,1,3] 
        sa(stacks);
    else if (a == 1 && b == 2 && c == 0)   // [2,3,1]
        rra(stacks);
    else if (a == 2 && b == 0 && c == 1)   // [3,1,2]
        ra(stacks);
    else if (a == 2 && b == 1 && c == 0) { // [3,2,1]
        sa(stacks);
        rra(stacks);
    }
    // Caso [1,2,3] (a=0,b=1,c=2) já está ordenado - não faz nada
}

void sort_four(t_stacks *stacks) {
    // Empurrar o menor (index = 0) para B
    int pos = find_position_by_index(stacks->a, 0);
    
    if (pos == 1) sa(stacks);
    else if (pos == 2) { ra(stacks); ra(stacks); }
    else if (pos == 3) rra(stacks);
    
    pb(stacks);
    sort_three(stacks);
    pa(stacks);
}

void sort_five(t_stacks *stacks) {
    // Empurrar os dois menores (index = 0 e 1) para B
    int pos;
    
    // Primeiro, empurrar o menor (0)
    pos = find_position_by_index(stacks->a, 0);
    if (pos == 1) sa(stacks);
    else if (pos == 2) { ra(stacks); ra(stacks); }
    else if (pos == 3) { rra(stacks); rra(stacks); }
    else if (pos == 4) rra(stacks);
    pb(stacks);
    
    // Depois, empurrar o segundo menor (1)
    pos = find_position_by_index(stacks->a, 1);
    if (pos == 1) sa(stacks);
    else if (pos == 2) { ra(stacks); ra(stacks); }
    else if (pos == 3) rra(stacks);
    pb(stacks);
    
    sort_three(stacks);
    pa(stacks);
    pa(stacks);
}

void sort_small(t_stacks *stacks) {
    if (stacks->size_a == 4)
        sort_four(stacks);
    else if (stacks->size_a == 5)
        sort_five(stacks);
    else {
        // Para casos maiores que 5 mas menores que o limiar do Turk
        while (stacks->size_a > 3) {
            int min_pos = find_position_by_index(stacks->a, find_min_index(stacks->a));
            
            if (min_pos <= stacks->size_a / 2) {
                while (min_pos--) ra(stacks);
            } else {
                while (min_pos++ < stacks->size_a) rra(stacks);
            }
            pb(stacks);
        }
        sort_three(stacks);
        while (stacks->size_b > 0) pa(stacks);
    }
}
