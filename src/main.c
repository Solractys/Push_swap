/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		x;
	t_stack	*stack;
	int		flag;
	char	**inputs;

	
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	x = 1;
	flag = 0;
	while (argv[x] != NULL)
	{
		if (!validate_input(argv[x]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		x++;
	}
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
			return (0);
		}
	}
	if (check_sorted(stack))
	{
		free_stack(&stack);
		return (0);
	}
	sort_func(&stack);
	free_stack(&stack);
	if (flag)
	{
		int count = 0;
		while (inputs[count] != NULL)
			free(inputs[count++]);
		free(inputs);
	}
	return (0);
}
