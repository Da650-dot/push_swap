/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:16:21 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:16:24 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack_node **b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_putendl_fd("rrr", 1);
}