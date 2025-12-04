/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdint.h>

int	check_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	down;

	top = (*stack)->number;
	mid = (*stack)->next->number;
	down = (*stack)->next->next->number;
	if (top == mid && top == down)
		return (1);
	if (top == mid && top < down)
		return (1);
	if (top < mid && top < down)
		return (1);
	else
		return (0);
}

void	sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	down;

	top = (*stack)->number;
	mid = (*stack)->next->number;
	down = (*stack)->next->next->number;
	if (top > mid && top > down)
		rotate(stack);
	if (top > mid && top < down)
		swap(stack);
	if (top == mid)
		reverse_rotate(stack);
	if (top == down)
		reverse_rotate(stack);
	return ;
}
