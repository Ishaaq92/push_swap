/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:01:55 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/26 11:29:13 by isahmed          ###   ########.fr       */
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

static void	check_duplicates(t_data *data, int *array)
{
	int	i;

	i = -1;
	while ((++i) < (data->stack_a->size - 1))
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			free_ll(data, 1);
		}
	}
}

void	init_normalise(t_data *data)
{
	t_node	*node;
	int		*array;
	int		i;

	i = 0;
	array = malloc(sizeof(int) * (data->stack_a->size + 1));
	if (!array)
		return ;
	node = data->stack_a->top;
	while (node)
	{
		array[i++] = node->num;
		node = node->next;
	}
	array[i] = 0;
	node = data->stack_a->top;
	bubble_sort(array, data->stack_a->size);
	normalise(data->stack_a, array);
	check_duplicates(data, array);
	free(array);
}
