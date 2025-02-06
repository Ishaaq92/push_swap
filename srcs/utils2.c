#include "../push_swap.h"

int	find_max(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	t_node			*node;
	int				max;

	if (chunk->loc == TOP_A || chunk->loc == BOTTOM_A)
		stack = data ->stack_a;
	else
		stack = data -> stack_b;
	node = stack -> top;
	max = node->num; 
	while (node)
	{
		if (node->num > max)
			max = node->num;
		node = node -> next;
	}
	return (max);
}

int	find_min(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	t_node			*node;
	int				min;

	if (chunk->loc == TOP_A || chunk->loc == BOTTOM_A)
		stack = data ->stack_a;
	else
		stack = data -> stack_b;
	node = stack -> top;
	min = node->num; 
	while (node)
	{
		if (node->num < min)
			min = node->num;
		node = node -> next;
	}
	return (min);
}