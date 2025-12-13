/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:03:47 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 12:43:34 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_values(long *a, long *b);

long	*create_sorted_array(t_stack *stack, int size)
{
	int		i;
	int		j;
	long	*array;

	array = malloc(sizeof(long) * size);
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < size && stack)
	{
		array[i] = stack->number;
		stack = stack->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
				swap_values(&array[i], &array[j]);
		}
	}
	return (array);
}

static void	swap_values(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	assign_indices(t_stack *stack, long *sorted_array, int size)
{
	int		i;
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current->number == sorted_array[i])
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
	int		count;
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
	long	*sorted_array;
	int		size;

	size = count_stack(stack);
	sorted_array = create_sorted_array(stack, size);
	if (sorted_array == NULL)
		return ;
	assign_indices(stack, sorted_array, size);
	free(sorted_array);
}
