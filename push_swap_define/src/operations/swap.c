/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:15:37 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:15:43 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack_node **a, int print)
{
	swap(a);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack_node **b, int print)
{
	swap(b);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putendl_fd("ss", 1);
}
