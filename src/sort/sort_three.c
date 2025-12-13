/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 12:24:07 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdint.h>

int	check_three(t_stack **stack)
{
	long	top;
	long	mid;
	long	down;

	top = (*stack)->index;
	mid = (*stack)->next->index;
	down = (*stack)->next->next->index;
	if (top == mid && top == down)
		return (1);
	if (top == mid && top < down)
		return (1);
	if (top < mid && top < down)
		return (1);
	else
		return (0);
}

void	sort_three_by_number(t_stack **stack)
{
	long	a;
	long	b;
	long	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a > b && a > c)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	if (b > a && b > c)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if ((*stack)->number > (*stack)->next->number)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}

void	sort_three(t_stack **stack)
{
	long	a;
	long	b;
	long	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && a > c)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	if (b > a && b > c)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if ((*stack)->index > (*stack)->next->index)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}
