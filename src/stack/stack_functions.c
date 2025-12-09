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

t_stack	*create(int number)
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

void	push(t_stack **stack, int number)
{
	t_stack	*new_node;

	new_node = create(number);
	new_node->next = *stack;
	*stack = new_node;
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	return (temp);
}

void	show_stack(t_stack *node, int stack_id)
{
	t_stack	*temp;

	temp = node;
	while (temp != NULL)
	{
		if (stack_id == 1)
		{
			ft_printf("STACK A -> ");
			ft_printf("\nnumber:%d | index: %d | position: %d\n",
				temp->number, temp->index, temp->position);
		}
		else if (stack_id == 2)
		{
			ft_printf("STACK B -> ");
			ft_printf("\nnumber:%d | index: %d |\
				position: %d | target_postion: %d | cost_b: %d | cost_a: %d \n",
				temp->number, temp->index, temp->position,
				temp->target_position, temp->cost_b, temp->cost_a);
		}
		temp = temp->next;
	}
}
