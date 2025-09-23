#include "../../includes/push_swap.h"

static void execute_moves(t_stacks *stacks, int cost_a, int cost_b) {
    // Movimentos simultâneos
    while (cost_a > 0 && cost_b > 0) {
        rr(stacks);
        cost_a--; 
        cost_b--;
    }
    while (cost_a < 0 && cost_b < 0) {
        rrr(stacks);
        cost_a++; 
        cost_b++;
    }

    // Movimentos individuais
    while (cost_a > 0) { ra(stacks); cost_a--; }
    while (cost_a < 0) { rra(stacks); cost_a++; }
    while (cost_b > 0) { rb(stacks); cost_b--; }
    while (cost_b < 0) { rrb(stacks); cost_b++; }
}

static int calculate_total_cost(int cost_a, int cost_b) {
    int total_cost = abs(cost_a) + abs(cost_b);
    
    // Otimização para movimentos simultâneos
    if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0)) {
        total_cost = (abs(cost_a) > abs(cost_b)) ? abs(cost_a) : abs(cost_b);
    }
    
    return total_cost;
}

static void find_and_execute_best_move(t_stacks *stacks) {
    int best_cost = INT_MAX;
    int best_pos = 0;
    int best_cost_a = 0;
    int best_cost_b = 0;
    
    // Calcular custo para cada elemento em B
    for (int pos = 0; pos < stacks->size_b; pos++) {
        t_node *current = stacks->b;
        for (int i = 0; i < pos; i++)
            current = current->next;
        
        int target_pos = find_target_position(stacks, current->index);
        int cost_a = calculate_cost_a(stacks, target_pos);
        int cost_b = calculate_cost_b(stacks, pos);
        int total_cost = calculate_total_cost(cost_a, cost_b);
        
        if (total_cost < best_cost) {
            best_cost = total_cost;
            best_pos = pos;
            best_cost_a = cost_a;
            best_cost_b = cost_b;
        }
    }

    // Executar o melhor movimento
    execute_moves(stacks, best_cost_a, best_cost_b);
    pa(stacks);
}

static void final_rotation(t_stacks *stacks) {
    // Rotacionar A para que fique ordenado
    int min_pos = 0;
    int pos = 0;
    t_node *current = stacks->a;
    t_node *min_node = current;

    while (current) {
        if (current->index < min_node->index) {
            min_node = current;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }

    if (min_pos <= stacks->size_a / 2) {
        while (min_pos--) ra(stacks);
    } else {
        while (min_pos++ < stacks->size_a) rra(stacks);
    }
}

void turk_algorithm(t_stacks *stacks) {
    // Fase 1: Empurrar elementos para B, deixando apenas 3 em A
    while (stacks->size_a > 3) {
        pb(stacks);
    }

    // Ordenar os 3 elementos restantes em A
    sort_three(stacks);

    // Fase 2: Retornar elementos de B para A na posição correta
    while (stacks->size_b > 0) {
        find_and_execute_best_move(stacks);
    }

    // Fase 3: Rotação final para ordenar A
    final_rotation(stacks);
}