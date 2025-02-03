/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:23:56 by ishaaq            #+#    #+#             */
/*   Updated: 2025/02/03 16:00:31 by isahmed          ###   ########.fr       */
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
			sort_two_b(data, chunk);
		else
			sort_one(data, chunk);
	}
}
static	void	rec_routing(t_split *split, t_chunk *chunk, int i)
{
	split->max.loc = TOP_A;
	split->min.loc = TOP_B;
	split->max.size = i;
	split->min.size = chunk->size - i;
	ft_printf("max (%d)\n", split->max.size);
	ft_printf("min (%d)\n", split->min.size);
}

void	splitting_a(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;	
	t_split			split;
	int				pivot;
	int				i;
	
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
	rec_routing(&split, chunk, i);
	splitting_a(data, &split.max);
	splitting_b(data, &split.min);
}

void	splitting_b(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;	
	t_split			split;
	int				pivot;
	int				i;
	
	i = 0;
	if (chunk ->size <= 3)
		return (non_rec_routing(data, chunk));
	pivot = (chunk->size / 2) + find_min(data, chunk);
	if (pivot == 0)
		return;
	while (i < (chunk->size / 2))
	{
		while (data->stack_b->top->num <= pivot)
			rb(data->stack_b);
		pa(data);
		i ++;
	}
	rec_routing(&split, chunk, i);
	splitting_a(data, &split.max);
	splitting_b(data, &split.min);
}
