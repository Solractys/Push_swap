/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:44:11 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 12:49:06 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	long				number;
	int					index;
	int					position;
	int					cost_a;
	int					cost_b;
	int					target_position;
	struct s_stack		*next;
}	t_stack;
// CRUD STACK
t_stack	*create(long number);
void	push(t_stack **node, long number);
void	free_stack(t_stack **stack);
// MOVEMENTS
void	swap(t_stack **node);
void	push_to(t_stack **org, t_stack **dest);
void	rotate(t_stack **node);
void	rotate_both(t_stack **stack_A, t_stack **stack_B);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_both(t_stack **stack_A, t_stack **stack_B);
//VALIDATION
t_stack	*parse_values(char **input);
int		validate_input(char *inputs);
int		check_duplicate(t_stack *stack, long num);
int		check_sorted(t_stack *stack);
void	push_swap(int argc, char **argv);
//SORTING
int		check_two(t_stack **stack);
void	sort_two(t_stack **stack);
int		check_three(t_stack **stack);
void	sort_three_by_number(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_func(t_stack **stack);
// index system
long	*create_sorted_array(t_stack *stack, int size);
void	assign_indices(t_stack *stack, long *sorted_array, int size);
int		count_stack(t_stack *stack);
void	index_stack(t_stack *stack);
// PUSH TO B
int		find_min_index(t_stack *stack);
int		should_rotate(t_stack *stack, int size);
void	push_all(t_stack **stack_a, t_stack **stack_b);
// TURK ALGO
void	update_position(t_stack *stack);
void	update_positions(t_stack **stack_a, t_stack **stack_b);
int		find_min_position(t_stack *stack);
int		find_target_position(t_stack *stack, int b_index);
void	find_targets(t_stack **stack_a, t_stack **stack_b);
void	calculate_costs(t_stack **stack_a, t_stack **stack_b);
int		calculate_total_cost(t_stack *element);
t_stack	*find_cheapest(t_stack *stack_b);
void	rotate_by_cost(t_stack **stack, int cost, char name);
void	rotate_both_by_cost(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
void	final_rotate(t_stack **stack_a);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
#endif
