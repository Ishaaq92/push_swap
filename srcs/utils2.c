/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:05:48 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/26 15:54:54 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_order(t_data *data)
{
	t_node	*node;

	node = data->stack_a->top;
	while (node ->next)
	{
		if (node->next->num < node->num)
			return (1);
		node = node->next;
	}
	return (0);
}
