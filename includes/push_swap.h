#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct t_node
{
	struct t_node	*next;
	int	number;
}	t_node;

t_node	*create(int number);
void	push(t_node *node, int number);
t_node	*pop(t_node *node);

#endif
