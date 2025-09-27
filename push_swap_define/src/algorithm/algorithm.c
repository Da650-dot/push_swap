/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:18:15 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 18:40:48 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_total_cost(int cost_a, int cost_b)
{
	int	total_cost;

	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs(cost_a) > abs(cost_b))
			total_cost = abs(cost_a);
		else
			total_cost = abs(cost_b);
	}
	else
		total_cost = abs(cost_a) + abs(cost_b);
	return (total_cost);
}

void	find_best_move(t_stack_node **a, t_stack_node **b)
{
	int	best_cost;
	int	best_cost_a;
	int	best_cost_b;
	int	pos;
	int	cost_a;
	int	cost_b;
	int	total_cost;

	best_cost = INT_MAX;
	pos = 0;
	while (pos < stack_size(*b))
	{
		calculate_costs(*a, *b, pos, &cost_a, &cost_b);
		total_cost = calculate_total_cost(cost_a, cost_b);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			best_cost_a = cost_a;
			best_cost_b = cost_b;
		}
		pos++;
	}
	execute_moves(a, b, best_cost_a, best_cost_b);
}

int	find_min_pos(t_stack_node *stack)
{
	t_stack_node	*min;
	int				min_pos;
	t_stack_node	*current;

	min = find_min(stack);
	min_pos = 0;
	current = stack;
	while (current != min)
	{
		min_pos++;
		current = current->next;
	}
	return (min_pos);
}

void	final_rotation(t_stack_node **a)
{
	int	min_pos;
	int	size_a;

	min_pos = find_min_pos(*a);
	size_a = stack_size(*a);
	if (min_pos <= size_a / 2)
	{
		while (min_pos > 0)
		{
			ra(a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size_a)
		{
			rra(a, 1);
			min_pos++;
		}
	}
}