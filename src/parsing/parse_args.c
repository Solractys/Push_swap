/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 10:26:32 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*parse_values(char **input)
{
	int		x;
	int		count;
	t_stack	*stack;
	long	num;

	count = 0;
	stack = NULL;
	while (input[count])
		count++;
	x = count - 1;
	while (x >= 0)
	{
		if (ft_strlen(input[x]) > 11)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(&stack);
			return (NULL);
		}
		num = ft_atoi(input[x]);
		if (num < INT_MIN || num > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(&stack);
			return (NULL);
		}
		if( check_duplicate(stack, num))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(&stack);
			return (NULL);
		}
		push(&stack, num);
		x--;
	}
	return (stack);
}

int	check_duplicate(t_stack *stack, long num)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->number == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (1);
	temp = stack;
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}
