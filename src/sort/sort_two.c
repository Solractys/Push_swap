/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/08 15:08:05 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_two(t_stack **stack)
{
	int	top;
	int	down;

	top = (*stack)->number;
	down = (*stack)->next->number;
	if (top < down || top == down)
		return (1);
	return (0);
}

void	sort_two(t_stack **stack)
{
	long	n1;
	long	n2;

	if (stack == NULL)
		return ;
	n1 = (*stack)->number;
	n2 = (*stack)->next->number;
	if (n1 == n2)
		return ;
	if (n1 > n2)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}
