/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:28:04 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/29 22:48:41 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack    *create(int number)
{
	t_stack    *node;
	node = ft_calloc(sizeof(t_stack), 1);
	node->number = number;
	node->next = NULL;
	return (node);
}

void	push(t_stack **stack, int number)
{
	t_stack *new_node = create(number);
	new_node->next = *stack;
	*stack = new_node;
}

t_stack	*pop(t_stack **stack)
{
	if(*stack == NULL)
		return (NULL);
	t_stack *temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	return (temp);
}

void	show_stack(t_stack *node)
{
    t_stack *temp = node;
    while (temp != NULL)
    {
        ft_printf("\t\t[ %d ]\n", temp->number);
        temp = temp->next;
    }
}
void	swap(t_stack **stack)
{
	if (stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	t_stack *top_item = pop(stack);
	t_stack *scd_top_item = pop(stack);
	push(stack, top_item->number);
	push(stack, scd_top_item->number);
}

void	swap_both(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A == NULL || *stack_B == NULL)
		return ;
	swap(stack_A);
	swap(stack_B);
}

void	push_to(t_stack **stack_A, t_stack **stack_B)
{
	if (stack_A == NULL)
		return ;
	t_stack *temp = *stack_A;
	*stack_A = (*stack_A)->next;

	temp->next = *stack_B;
	*stack_B = temp;
}


void	rotate(t_stack **stack)
{
	t_stack	*stack_b = NULL;
	t_stack	*stack_c = *stack;
	*stack = (*stack)->next;
	while (*stack != NULL)
		push_to(stack, &stack_b);
	push_to(&stack_c, stack);
	while (stack_b != NULL)
		push_to(&stack_b, stack);
}

void	rotate_both(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A == NULL || *stack_B == NULL)
		return ;
	rotate(stack_A);
	rotate(stack_B);
}

void	reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	t_stack *last = (*stack)->next;
	t_stack *penultimate = *stack;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
}
void	reverse_rotate_both(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A == NULL ||*stack_B == NULL)
		return ;
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
}

int	main(void)
{
    // STACK CREATE
	t_stack    *stack = NULL;
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	show_stack(stack);
    // SWAP MOVE
	ft_printf("\nSA :");
	swap(&stack);
	show_stack(stack);

    // PUSH MOVE
	t_stack    *stack_A = NULL;
	t_stack    *stack_B = NULL;
	push(&stack_A, 1);
	push(&stack_A, 2);
	push(&stack_A, 3);

	push(&stack_B, 4);
	push(&stack_B, 5);
	ft_printf("PA MOVE:\n");
	show_stack(stack_A);
	ft_printf("\n");
	show_stack(stack_B);

	ft_printf("AFTER PA MOVE:\n");
	push_to(&stack_A, &stack_B);
	show_stack(stack_A);
	ft_printf("\n");
	show_stack(stack_B);

    //ROTATE MOVE
	ft_printf("ROTATE MOVE: \n");
	show_stack(stack);
	ft_printf("AFTER \n");
	rotate(&stack);
	show_stack(stack);
    // REVERSE ROTATE MOVE
	ft_printf("REVERSE ROTATE MOVE: \n");
	show_stack(stack);
	reverse_rotate(&stack);
	ft_printf("AFTER \n");
	show_stack(stack);
    return (0);
}
