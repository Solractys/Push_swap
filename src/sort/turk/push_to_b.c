/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:13:41 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 12:30:17 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_index(t_stack *stack)
{
	int	size;
	int	half;
	int	min_index;
	int	i;

	size = count_stack(stack);
	min_index = stack->index;
	half = size / 2;
	i = 0;
	while (stack && i < half)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int	should_rotate(t_stack *stack, int size)
{
	int	top_index;
	int	second_index;

	if (stack == NULL || stack->next == NULL)
		return (0);
	top_index = stack->index;
	second_index = stack->next->index;
	if (top_index - second_index > size / 4)
		return (1);
	return (0);
}

void	push_all(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	to_push;
	int	median;

	size = count_stack(*stack_a);
	to_push = size - 3;
	median = size / 2;
	while (to_push > 0)
	{
		if ((*stack_a)->index < median || !should_rotate(*stack_a, size))
		{
			push_to(stack_a, stack_b);
			ft_printf("pb\n");
			to_push--;
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
}
