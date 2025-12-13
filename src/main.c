/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 10:23:48 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		x;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	x = 1;
	while (argv[x] != NULL)
	{
		if (!validate_input(argv[x]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		x++;
	}
	if (argc == 2 && argv[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	push_swap(argc, argv);
	return (0);
}
