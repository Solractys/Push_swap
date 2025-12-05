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

	index_stack(stack);
	push_all(&stack, &stack_b);
	ft_printf("1 ETAPA:\n");
	show_stack(stack, 1);
	show_stack(stack_b, 2);

	ft_printf("2 ETAPA:\n");
	sort_three(&stack);
	show_stack(stack, 1);

	ft_printf("3 ETAPA:\n");
	push_back_to_a(&stack, &stack_b);
	show_stack(stack, 1);

	ft_printf("4 ETAPA:\n");
	final_rotate(&stack);
	ft_printf("\n");
	show_stack(stack, 1);
	return (0);
}
