/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create(long number)
{
	t_stack	*node;

	node = ft_calloc(sizeof(t_stack), 1);
	node->number = number;
	node->position = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->target_position = 0;
	node->next = NULL;
	return (node);
}

void	push(t_stack **stack, long number)
{
	t_stack	*new_node;

	new_node = create(number);
	new_node->next = *stack;
	*stack = new_node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
