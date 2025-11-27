/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/27 09:32:20 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create(int number)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	push(t_node *node, int number)
{
	t_node	*new_node = create(number);
	new_node->next = NULL;
	if (node->next != NULL)
	{
		t_node *tmp = node->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		node->next = new_node;
}
t_node	*pop(t_node *node)
{
	if (node->next == NULL)
		return (NULL);
	else
	{
		t_node *last;
		t_node	*penultimate;
		
		last = node->next;
		penultimate = node;
		while (last->next != NULL)
		{
			penultimate = last;
			last = last->next;
		}
		penultimate->next = NULL;
		return (last);
	}

}

int	main(void)
{
	t_node	*node = create(1);
	ft_printf("%d\n", node->number);
	push(node, 2);
	ft_printf("%d\n", node->next->number);
	push(node, 3);
	ft_printf("%d\n", node->next->next->number);
	push(node, 4);
	ft_printf("%d\n\n", node->next->next->next->number);

	while (node != NULL)
	{
		t_node *droped = pop(node);
		if (droped == NULL)
		{
			ft_printf("%d\n", node->number);
			break ;
		}
		ft_printf("%d\n", droped->number);
	}
	return (0);
}
