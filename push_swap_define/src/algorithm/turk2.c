/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:44:45 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 19:03:00 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	chunk_size;
	int	i;

	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	i = 0;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index <= i)
			push_element_to_b(a, b, &i);
		else if ((*a)->index <= i + chunk_size)
			push_and_rotate_b(a, b, &i);
		else
			ra(a, 1);
	}
}

void	execute_positive_moves(t_stack_node **a, t_stack_node **b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ra(a, 1);
		rb(b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	execute_negative_moves(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rra(a, 1);
		rrb(b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_remaining_a_moves(t_stack_node **a, int cost_a)
{
	while (cost_a > 0)
	{
		ra(a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, 1);
		cost_a++;
	}
}

void	execute_remaining_b_moves(t_stack_node **b, int cost_b)
{
	while (cost_b > 0)
	{
		rb(b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, 1);
		cost_b++;
	}
}