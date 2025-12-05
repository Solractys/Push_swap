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

void sort_three(t_stack **stack)
{
    int a = (*stack)->index;
    int b = (*stack)->next->index;
    int c = (*stack)->next->next->index;

    if (a > b && a > c)
    {
        rotate(stack);
        ft_printf("ra\n");
        a = (*stack)->index;
        b = (*stack)->next->index;
        c = (*stack)->next->next->index;
    }

    if (b > a && b > c)
    {
        reverse_rotate(stack);
        ft_printf("rra\n");
        a = (*stack)->index;
        b = (*stack)->next->index;
        c = (*stack)->next->next->index;
    }

    if (a > b)
    {
        swap(stack);
        ft_printf("sa\n");
    }
}

