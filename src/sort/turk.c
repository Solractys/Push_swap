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
			to_push--;
		}
		else if (should_rotate(*stack_a, size))
		{
			rotate(stack_a);
		}
		else
		{
			push_to(stack_a, stack_b);
			to_push--;
		}
	}
}
