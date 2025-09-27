/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sou2 <danilo.bleach12@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:14:04 by dde-sou2          #+#    #+#             */
/*   Updated: 2025/09/27 19:07:09 by dde-sou2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* Main functions */
void			push_swap(t_stack_node **a, t_stack_node **b);

/* Operations */
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **a, t_stack_node **b, int print);
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node **b, int print);
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);

/* Algorithms */
void			sort_two(t_stack_node **a);
void			sort_three(t_stack_node **a);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			sort_large(t_stack_node **a, t_stack_node **b);

/* Utils */
t_stack_node	*stack_new(int value);
void			stack_add_back(t_stack_node **stack, t_stack_node *new_node);
t_stack_node	*stack_last(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
void			stack_clear(t_stack_node **stack);

/* Validation */
int				is_sorted(t_stack_node *stack);
int				has_duplicates(t_stack_node *stack);
void			normalize_stack(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/* Parsing */
t_stack_node	*parse_args(int argc, char **argv);
int				validate_number(char *str);
void			error_exit(t_stack_node **a, t_stack_node **b);

/* Libft functions */
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
long			ft_atol(const char *str);
char			**ft_split(char const *s, char c);


/* Algorithm helpers */
void			push_chunks_to_b(t_stack_node **a, t_stack_node **b);
void			execute_moves(t_stack_node **a, t_stack_node **b,
					int cost_a, int cost_b);
void			find_best_move(t_stack_node **a, t_stack_node **b);
int				find_min_pos(t_stack_node *stack);
void			final_rotation(t_stack_node **a);
void			calculate_costs(t_stack_node *a, t_stack_node *b, int pos, int *cost_a, int *cost_b);
// push_swap.h
int find_target_position(t_stack_node *a, int b_index);
void push_element_to_b(t_stack_node **a, t_stack_node **b, int *i);
void push_and_rotate_b(t_stack_node **a, t_stack_node **b, int *i);
void	execute_positive_moves(t_stack_node **a, t_stack_node **b,
			int *cost_a, int *cost_b);
void	execute_remaining_a_moves(t_stack_node **a, int cost_a);
void	execute_remaining_b_moves(t_stack_node **b, int cost_b);
void	execute_negative_moves(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b);
void	execute_positive_moves(t_stack_node **a, t_stack_node **b,
			int *cost_a, int *cost_b);

#endif