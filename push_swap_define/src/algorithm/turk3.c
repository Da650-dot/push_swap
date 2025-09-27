/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:45:13 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 19:06:50 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves(t_stack_node **a, t_stack_node **b,
		int cost_a, int cost_b)
{
	execute_positive_moves(a, b, &cost_a, &cost_b);
	execute_negative_moves(a, b, &cost_a, &cost_b);
	execute_remaining_a_moves(a, cost_a);
	execute_remaining_b_moves(b, cost_b);
}

void	sort_large(t_stack_node **a, t_stack_node **b)
{
	push_chunks_to_b(a, b);
	if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 2)
		sort_two(a);
	while (*b)
	{
		find_best_move(a, b);
		pa(a, b, 1);
	}
	final_rotation(a);
}
void	calculate_costs(t_stack_node *a, t_stack_node *b,
			int pos, int *cost_a, int *cost_b)
{
	t_stack_node	*current_b;
	int				target_pos;
	int				i;

	current_b = b;
	i = 0;
	while (i < pos)
	{
		current_b = current_b->next;
		i++;
	}
	target_pos = find_target_position(a, current_b->index);
	*cost_a = target_pos;
	*cost_b = pos;
	if (*cost_a > stack_size(a) / 2)
		*cost_a = *cost_a - stack_size(a);
	if (*cost_b > stack_size(b) / 2)
		*cost_b = *cost_b - stack_size(b);
}