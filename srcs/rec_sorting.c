/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:23:56 by ishaaq            #+#    #+#             */
/*   Updated: 2025/02/03 09:53:18 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	non_rec_routing(t_data *data, t_chunk *chunk)
{
	if (chunk->loc == TOP_A || chunk->loc == BOTTOM_A)
	{
		if (chunk->size == 3)
			sort_three_a(data, chunk);
		else if (chunk->size == 2)
			sort_two_a(data, chunk);
		else
			sort_one(data, chunk);
	}
	else
	{
		if (chunk->size == 3)
			sort_three_b(data, chunk);
		else if (chunk->size == 2)
			sort_two_a(data, chunk);
		else
			sort_one(data, chunk);
	}
}
static	rec_routing(t_data *data, t_split *split)
{

	if (split->max == TOP_A || split->max->loc == BOTTOM_A)
	{

	}

}

void	splitting(t_data *data, t_chunk *chunk)
{
	t_split	split;
	int		pivot;
	int		i;
	
	i = 0;
	if (chunk ->size <= 3)
		return (non_rec_routing(data, chunk));
	pivot = (chunk->size / 2) + find_min(data, chunk);
	if (pivot == 0)
		return;
	while (i < (chunk->size / 2))
	{
		while (data->stack_a->top->num >= pivot)
			ra(data->stack_a);
		pb(data);
		i ++;
	}
	split.max.size = chunk->size - i;
	split.max.loc = TOP_A;
	// split.min.size = i;
	// split.min.loc = TOP_B;
	splitting(data, &split.max);
}

void	shift_to_top(t_data *data, t_chunk *chunk, t_linked_list *stack)
{
	if (chunk -> loc == TOP_A || chunk ->loc == BOTTOM_A)
	{
		if (chunk ->loc == BOTTOM_A)
		{
			rra(data -> stack_a);
			rra(data -> stack_a);
			rra(data -> stack_a);
		}
	}
	stack = data -> stack_a;
	if (chunk -> loc == TOP_B)
		stack = data -> stack_b;
}
