/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:20:27 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/08 15:45:01 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_position(t_stack *stack)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}

void	update_positions(t_stack **stack_a, t_stack **stack_b)
{
	update_position(*stack_a);
	update_position(*stack_b);
}

int	find_min_position(t_stack *stack)
{
	int	min_index;
	int	min_position;

	if (!stack)
		return (0);
	min_index = stack->index;
	min_position = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_position = stack->position;
		}
		stack = stack->next;
	}
	return (min_position);
}

int	find_target_position(t_stack *stack, int b_index)
{
	int		target_index;
	int		closest_index;
	t_stack	*current;

	closest_index = INT_MAX;
	target_index = -1;
	current = stack;
	while (current)
	{
		if (current->index > b_index && current->index < closest_index)
		{
			closest_index = current->index;
			target_index = current->position;
		}
		current = current->next;
	}
	if (target_index == -1)
		target_index = find_min_position(stack);
	return (target_index);
}

void	find_targets(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;

	b = *stack_b;
	while (b)
	{
		b->target_position = find_target_position(*stack_a, b->index);
		b = b->next;
	}
}
