/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:24:18 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/08 15:33:06 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both_by_cost(t_stack **stack_a, t_stack **stack_b,
					int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_both(stack_a, stack_b);
		ft_printf("rr\n");
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b);
		ft_printf("rrr\n");
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	cheapest = find_cheapest(*stack_b);
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	if (cost_a != 0 && cost_b != 0)
		rotate_both_by_cost(stack_a, stack_b, &cost_a, &cost_b);
	rotate_by_cost(stack_a, cost_a, 'a');
	rotate_by_cost(stack_b, cost_b, 'b');
	push_to(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		update_positions(stack_a, stack_b);
		find_targets(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
}

void	final_rotate(t_stack **stack_a)
{
	int	min_position;
	int	size;

	update_position(*stack_a);
	min_position = find_min_position(*stack_a);
	size = count_stack(*stack_a);
	if (min_position <= size / 2)
	{
		while (min_position > 0 && (*stack_a)->index != 0)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			min_position--;
		}
	}
	else
	{
		while (min_position < size && (*stack_a)->index != 0)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			min_position++;
		}
	}
}
