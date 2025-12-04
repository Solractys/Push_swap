/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = (*stack)->next;
	penultimate = *stack;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate_both(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A == NULL || *stack_B == NULL)
		return ;
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
}
