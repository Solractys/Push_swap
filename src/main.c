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
// CRUD STACK
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
// MOVES
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
// ERROR HANDLING
int	validate_input(char *inputs)
{
	int y = 0;

	if (inputs == NULL || inputs[0] == '\0')
			return (0);
		while (inputs[y])
		{
			if (inputs[y] == '+' || inputs[y] == '-')
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

t_stack	*parse_values(char **input)
{
	int x = 1;
	t_stack *stack = NULL;
	while (input[x])
	{
		push(&stack, ft_atoi(input[x]));
		x++;
	}
	return (stack);
}
int	check_three(t_stack **stack)
{
	int	top = (*stack)->number;
	int	mid = (*stack)->next->number;
	int down = (*stack)->next->next->number;

	if (top < mid && top < down)
		return (1);
	else
		return (0);
}

void	sort_three(t_stack **stack)
{
	int top, mid, down = 0;
	top = (*stack)->number;
	mid = (*stack)->next->number;
	down = (*stack)->next->next->number;

	if (top > mid && top > down)
		rotate(stack);
	else if (top > mid && top < down)
		swap(stack);
	else if (top < mid && top < down)
		return ;
}

void sort_func(t_stack **stack)
{
	while (check_three(stack) == 0)
			sort_three(stack);
}

int	main(int argc, char **argv)
{
	int x = 1;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (argv[x] != NULL)
	{
		if(!validate_input(argv[x]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		x++;
	}
	
	t_stack *stack = NULL;
	stack = parse_values(argv);
	show_stack(stack);
	ft_printf("\n");
	sort_func(&stack);
	show_stack(stack);


    // PUSH MOVE
// 	t_stack    *stack_B = NULL;
// 	push(&stack_B, 4);
// 	push(&stack_B, 5);
// 	ft_printf("PA MOVE:\n");
// 	show_stack(stack);
// 	ft_printf("\n");
// 	show_stack(stack_B);
// 
// 	ft_printf("AFTER PA MOVE:\n");
// 	push_to(&stack, &stack_B);
// 	show_stack(stack);
// 	ft_printf("\n");
// 	show_stack(stack_B);
// 
//     //ROTATE MOVE
// 	ft_printf("ROTATE MOVE: \n");
// 	show_stack(stack);
// 	ft_printf("AFTER \n");
// 	rotate(&stack);
// 	show_stack(stack);
//     // REVERSE ROTATE MOVE
// 	ft_printf("REVERSE ROTATE MOVE: \n");
// 	show_stack(stack);
// 	reverse_rotate(&stack);
// 	ft_printf("AFTER \n");
// 	show_stack(stack);
    return (0);
}
