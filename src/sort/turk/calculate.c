/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:21:34 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/08 15:46:41 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*b;

	size_a = count_stack(*stack_a);
	size_b = count_stack(*stack_b);
	b = *stack_b;
	while (b)
	{
		b->cost_b = b->position;
		if (b->position > size_b / 2)
			b->cost_b = (size_b - b->position) * -1;
		b->cost_a = b->target_position;
		if (b->target_position > size_a / 2)
			b->cost_a = (size_a - b->target_position) * -1;
		b = b->next;
	}
}

int	calculate_total_cost(t_stack *element)
{
	int	abs_a;
	int	abs_b;

	if (element->cost_a < 0)
		abs_a = -element->cost_a;
	else
		abs_a = element->cost_a;
	if (element->cost_b < 0)
		abs_b = -element->cost_b;
	else
		abs_b = element->cost_b;
	if ((element->cost_a > 0 && element->cost_b > 0)
		|| (element->cost_a < 0 && element->cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}

t_stack	*find_cheapest(t_stack *stack_b)
{
	int		min_cost;
	int		current_cost;
	t_stack	*cheapest;

	min_cost = INT_MAX;
	cheapest = stack_b;
	while (stack_b)
	{
		current_cost = calculate_total_cost(stack_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest);
}

void	rotate_by_cost(t_stack **stack, int cost, char name)
{
	while (cost > 0)
	{
		rotate(stack);
		ft_printf("r%c\n", name);
		cost--;
	}
	while (cost < 0)
	{
		reverse_rotate(stack);
		ft_printf("rr%c\n", name);
		cost++;
	}
}
