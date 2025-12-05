/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// START STEP 1
int	*create_sorted_array(t_stack *stack, int size)
{
	int	i;
	int	*array;
	t_stack	*current;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);
	current = stack;
	i = 0;
	while (current != NULL)
	{
		array[i] = current->number;
		current = current->next;
		i++;
	}
	int x = 0, y = 0;
	while (x < size - 1)
	{
		y = x + 1;
		while (y < size)
		{
			if (array[x] > array[y])
			{
				int temp = array[x];
				array[x] = array[y];
				array[y] = temp;
			}
			y++;
		}
		x++;
	}
	return (array);
}
void	assign_indices(t_stack *stack, int *sorted_arrat, int size)
{
	int	i;
	t_stack	*current;
	
	current = stack;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current->number == sorted_arrat[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

int	count_stack(t_stack *stack)
{
	int	count;
	t_stack	*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	index_stack(t_stack *stack)
{
	int	*sorted_array;
	int size;

	size = count_stack(stack);
	sorted_array = create_sorted_array(stack, size);
	if (sorted_array == NULL)
		return ;
	assign_indices(stack, sorted_array, size);
	free(sorted_array);
}

// START STEP 2
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
	int second_index;
	
	if (stack == NULL || stack->next == NULL)
		return (0);
	top_index = stack->index;
	second_index = stack->next->index;
	if (top_index  - second_index > size / 4)
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
		if ((*stack_a)->index < median)
		{
			push_to(stack_a, stack_b);
			ft_printf("pb\n");
			to_push--;
		}
		else if (should_rotate(*stack_a, size))
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			push_to(stack_a, stack_b);
			to_push--;
			ft_printf("pb\n");
		}
	}
}

// START STEP 3
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
		if(stack->index < min_index)
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
	int	target_index;
	int	closest_index;
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

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
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

	if ((element->cost_a > 0 && element->cost_b > 0) ||
	 	(element->cost_a < 0 && element->cost_b < 0))
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
	int	min_cost;
	int	current_cost;
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

void	rotate_both_by_cost(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
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
	int	cost_a;
	int	cost_b;
	
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

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(*stack_a);
	push_all(stack_a, stack_b);
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	final_rotate(stack_a);
}
