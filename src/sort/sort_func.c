/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_func(t_stack **stack)
{
	int		count;
	t_stack	*temp;

	if (stack == NULL)
		return ;
	count = 0;
	temp = *stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count == 2)
	{
		while (check_two(stack) == 0)
			sort_two(stack);
	}
	else if (count == 3)
	{
		while (check_three(stack) == 0)
			sort_three(stack);
	}
	else
		turk_sort(stack, NULL);
}
