/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*top_item;
	t_stack	*scd_top_item;

	if (stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	top_item = pop(stack);
	scd_top_item = pop(stack);
	push(stack, top_item->number);
	push(stack, scd_top_item->number);
}

void	swap_both(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A == NULL || *stack_B == NULL)
		return ;
	swap(stack_A);
	swap(stack_B);
}
