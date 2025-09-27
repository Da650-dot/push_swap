/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:16:00 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:16:02 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, int print)
{
	rotate(a);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack_node **b, int print)
{
	rotate(b);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putendl_fd("rr", 1);
}