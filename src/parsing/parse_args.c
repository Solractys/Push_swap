/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 11:37:40 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	validate_number(t_stack **stack, char *str, long num);
static int	check_overflow(char *str);

t_stack	*parse_values(char **input)
{
	int		x;
	int		count;
	t_stack	*stack;
	long	num;

	count = 0;
	stack = NULL;
	num = 0;
	while (input[count])
		count++;
	x = count - 1;
	while (x >= 0)
	{
		if (!validate_number(&stack, input[x], num))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(&stack);
			return (NULL);
		}
		num = ft_atoi(input[x]);
		push(&stack, num);
		x--;
	}
	return (stack);
}

static int	validate_number(t_stack **stack, char *str, long num)
{
	if (ft_strlen(str) > 11)
	{
		if (check_overflow(str))
			return (0);
	}
	num = (int)ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (check_duplicate(*stack, num))
		return (0);
	return (1);
}

static int	check_overflow(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 11)
	{
		if (str[i] != '0' && str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
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
