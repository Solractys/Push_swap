/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:49:55 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 11:22:19 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		free_input(char **inputs, int flag);
static t_stack	*parse_inputs(int argc, char **argv);

void	push_swap(int argc, char **argv)
{
	t_stack	*stack;

	stack = parse_inputs(argc, argv);
	if (stack == NULL)
		return ;
	if (check_sorted(stack))
	{
		free_stack(&stack);
		return ;
	}
	sort_func(&stack);
	free_stack(&stack);
}

static t_stack	*parse_inputs(int argc, char **argv)
{
	char	**inputs;
	t_stack	*stack;
	int		flag;

	flag = 0;
	stack = NULL;
	inputs = NULL;
	if (argc == 2 && !(argv[1][0] == '\0'))
	{
		inputs = ft_split(argv[1], ' ');
		stack = parse_values(inputs);
		flag = 1;
	}
	else
	{
		stack = parse_values(&argv[1]);
		if (stack == NULL)
		{
			free_stack(&stack);
			return (NULL);
		}
	}
	free_input(inputs, flag);
	return (stack);
}

static void	free_input(char **inputs, int flag)
{
	int	count;

	if (flag)
	{
		count = 0;
		while (inputs[count] != NULL)
			free(inputs[count++]);
		free(inputs);
	}
}
