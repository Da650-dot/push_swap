/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:19:19 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 17:19:22 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static t_stack_node	*parse_single_arg(char *arg)
{
	t_stack_node	*stack;
	char			**numbers;
	int				i;
	long			num;

	stack = NULL;
	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (NULL);
	i = 0;
	while (numbers[i])
	{
		if (!validate_number(numbers[i]))
			return (free(numbers), stack_clear(&stack), NULL);
		num = ft_atol(numbers[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (free(numbers), stack_clear(&stack), NULL);
		stack_add_back(&stack, stack_new((int)num));
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stack);
}

static t_stack_node	*parse_multi_args(int argc, char **argv)
{
	t_stack_node	*stack;
	int				i;
	long			num;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!validate_number(argv[i]))
			return (stack_clear(&stack), NULL);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (stack_clear(&stack), NULL);
		stack_add_back(&stack, stack_new((int)num));
		i++;
	}
	return (stack);
}

t_stack_node	*parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (parse_single_arg(argv[1]));
	else
		return (parse_multi_args(argc, argv));
}