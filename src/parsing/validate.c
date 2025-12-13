/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/13 11:23:17 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	has_duplicate_signals(char *elem);
static int	has_signal_middle(char *elem);

int	validate_input(char *inputs)
{
	int	y;

	y = 0;
	if (inputs == NULL || inputs[0] == '\0')
		return (0);
	if (ft_strlen(inputs) == 1 && (inputs[0] == '+' || inputs[0] == '-'))
		return (0);
	if (has_duplicate_signals(inputs))
		return (0);
	if (has_signal_middle(inputs))
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

static int	has_signal_middle(char *elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		if ((elem[i] == '+' || elem[i] == '-') && i != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	has_duplicate_signals(char *elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		if (elem[i] == '+' || elem[i] == '-')
		{
			if (i + 1 < (int)ft_strlen(elem))
			{
				if (elem[i + 1] == '+' || elem[i + 1] == '-')
				{
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}
