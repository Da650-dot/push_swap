/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:17:49 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 18:49:20 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_position(t_stack_node *a, int b_index)
{
	int				pos;
	int				target_pos;
	int				closest_bigger;
	t_stack_node	*current;

	pos = 0;
	target_pos = 0;
	closest_bigger = INT_MAX;
	current = a;
	while (current)
	{
		if (current->index > b_index && current->index < closest_bigger)
		{
			closest_bigger = current->index;
			target_pos = pos;
		}
		pos++;
		current = current->next;
	}
	if (closest_bigger == INT_MAX)
		target_pos = find_min_pos(a);
	return (target_pos);
}

void	push_element_to_b(t_stack_node **a, t_stack_node **b, int *i)
{
	pb(a, b, 1);
	(*i)++;
}

void	push_and_rotate_b(t_stack_node **a, t_stack_node **b, int *i)
{
	pb(a, b, 1);
	if (stack_size(*b) > 1)
		rb(b, 1);
	(*i)++;
}