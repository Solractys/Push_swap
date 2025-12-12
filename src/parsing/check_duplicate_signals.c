/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_signals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:29:20 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/11 21:36:02 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_duplicate_signals(char *elem)
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
					return (1);
			}
		}
		i++;
	}
	return (0);
}
