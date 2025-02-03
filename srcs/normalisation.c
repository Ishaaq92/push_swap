#include "../push_swap.h"

int	return_index(int *array, int value)
{
	int	i;

	i = 0;
	while (array[i] != value)
		i++;
	return (i);
}

static void	bubble_sort(int *array, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	normalise(t_linked_list *stack_a, int *array)
{
	t_node	*node;

	node = stack_a->top;
	while (node)
	{
		node->num = return_index(array, node->num);
		node = node->next;
	}
}

int	find_min(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	t_node			*node;
	int				min;

	if (chunk->loc == TOP_A || BOTTOM_A)
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

void    init_normalise(t_data *data)
{
	int     i;
	int     size;
	int     *array;
	t_node  *node;

	size = data->stack_a->size;
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	i = 0;
	node = data->stack_a->top;
	while (node)
	{
		array[i++] = node->num;
		node = node->next;
	}
	bubble_sort(array, size);
	normalise(data->stack_a, array);
	free(array);
}