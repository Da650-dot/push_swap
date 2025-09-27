/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:14:01 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 18:16:28 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	
	a = NULL;
	b = NULL;
	if (argc == 1)
	return (0);
	a = parse_args(argc, argv);
	if (!a)
	error_exit(&a, &b);
	if (has_duplicates(a))
	error_exit(&a, &b);
	normalize_stack(a);
	if (!is_sorted(a))
	push_swap(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
