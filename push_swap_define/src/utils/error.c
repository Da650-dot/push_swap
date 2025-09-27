/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:19:33 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:19:36 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack_node **a, t_stack_node **b)
{
	if (a)
		stack_clear(a);
	if (b)
		stack_clear(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}