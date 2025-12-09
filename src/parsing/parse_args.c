/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*parse_values(char **input)
{
	int		x;
	int		count;
	t_stack	*stack;

	count = 0;
	stack = NULL;
	while (input[count])
		count++;
	x = count - 1;
	while (x >= 1)
	{
		push(&stack, ft_atoi(input[x]));
		x--;
	}
	return (stack);
}
