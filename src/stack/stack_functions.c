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

void	show_stack(t_stack *node)
{
	t_stack	*temp;

	temp = node;
	while (temp != NULL)
	{
		ft_printf("\t\t[ %d ]\n", temp->number);
		temp = temp->next;
	}
}
