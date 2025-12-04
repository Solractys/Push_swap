/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*stack_b;
	t_stack	*stack_c;

	stack_b = NULL;
	stack_c = *stack;
	*stack = (*stack)->next;
	while (*stack != NULL)
		push_to(stack, &stack_b);
	push_to(&stack_c, stack);
	while (stack_b != NULL)
		push_to(&stack_b, stack);
}

void	rotate_both(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A == NULL || *stack_B == NULL)
		return ;
	rotate(stack_A);
	rotate(stack_B);
}
