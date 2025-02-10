/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:01:55 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/10 13:44:28 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = 0;
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

void	init_normalise(t_data *data)
{
	t_node	*node;
	int		*array;
	int		i;

	i = 0;
	data->full_size = data->stack_a->size;
	array = malloc(sizeof(int) * data->stack_a->size);
	if (!array)
		return ;
	node = data->stack_a->top;
	while (node)
	{
		array[i++] = node->num;
		node = node->next;
	}
	bubble_sort(array, data->stack_a->size);
	normalise(data->stack_a, array);
	free(array);
}
