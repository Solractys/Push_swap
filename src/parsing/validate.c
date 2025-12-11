/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/01 22:21:24 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	validate_input(char *inputs)
{
	int	y;

	y = 0;
	if (inputs == NULL || inputs[0] == '\0')
		return (0);
	while (inputs[y])
	{
		if (inputs[y] == '+' || inputs[y] == '-' || inputs[y] == ' ')
		{
			y++;
			continue ;
		}
		if (!ft_isdigit(inputs[y]))
			return (0);
		y++;
	}
	return (1);
}
