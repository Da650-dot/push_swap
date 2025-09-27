/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:17:31 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:17:35 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:16:38 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:16:44 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_three(t_stack_node **a)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->value == find_max(*a)->value)
		ra(a, 1);
	else if ((*a)->next->value == find_max(*a)->value)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

static void	push_min_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;
	int				current_size;
	int				min_pos;
	t_stack_node	*current;

	min = find_min(*a);
	current_size = stack_size(*a);
	min_pos = 0;
	current = *a;
	while (current != min)
	{
		min_pos++;
		current = current->next;
	}
	while (*a != min)
	{
		if (min_pos <= current_size / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	int	elements_to_push;
	int	i;

	elements_to_push = stack_size(*a) - 3;
	i = 0;
	while (i < elements_to_push)
	{
		push_min_to_b(a, b);
		i++;
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}