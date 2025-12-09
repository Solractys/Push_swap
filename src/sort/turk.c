/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/12/08 15:45:29 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(*stack_a);
	push_all(stack_a, stack_b);
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	final_rotate(stack_a);
}
