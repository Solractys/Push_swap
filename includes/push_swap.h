#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int		number;
	struct s_stack	*next;
}	t_stack;
// CRUD STACK
t_stack	*create(int number);
void	push(t_stack **node, int number);
t_stack	*pop(t_stack **node);
void	show_stack(t_stack *node);
// MOVEMENTS
void	swap(t_stack **node);
void	push_to(t_stack **org, t_stack **dest);
void	rotate(t_stack **node);
void	rotate_both(t_stack **stack_A, t_stack **stack_B);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_both(t_stack **stack_A, t_stack **stack_B);

t_stack	*parse_values(char **input);
int	validate_input(char *inputs);


int check_two(t_stack **stack);
void sort_two(t_stack **stack);
int	check_three(t_stack **stack);
void	sort_three(t_stack **stack);
void sort_func(t_stack **stack);

#endif
