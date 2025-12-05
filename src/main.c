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
	
	x = 1;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (argv[x] != NULL)
	{
		if (!validate_input(argv[x]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		x++;
	}
	stack = NULL;
	stack = parse_values(argv);
	t_stack	*stack_b = NULL;
	turk_sort(&stack, &stack_b);
	return (0);
}
