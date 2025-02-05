/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:23:56 by ishaaq            #+#    #+#             */
/*   Updated: 2025/02/05 17:30:54 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	non_rec_routing(t_data *data, t_chunk *chunk, int *flag)
{
	if (chunk->loc == TOP_A || chunk->loc == BOTTOM_A)
	{
		if (chunk->size == 3)
			sort_three_a(data);
		else if (chunk->size == 2)
			sort_two_a(data);
		else
			sort_one(data, chunk);
		if (chunk->size  <= 3)
			(*flag) = 1;
	}
	else
	{
		if (chunk->size == 3)
			sort_three_b(data);
		else if (chunk->size == 2)
			sort_two_b(data);
		else
			sort_one(data, chunk);
	}
}
static	void	rec_routing(t_split *split, t_chunk *chunk, int i, int *flag)
{
	if (chunk->loc == TOP_A || chunk->loc == BOTTOM_A)
	{
		split->max.loc = TOP_A;
		split->min.loc = TOP_B;
		split->max.size = chunk->size - i;
		split->min.size = i;
	}
	else
	{
		split->max.loc = TOP_A;
		split->min.loc = TOP_B;
		split->max.size =  i;
		split->min.size = chunk->size - i;
		(*flag) = 1;
	}	
	// ft_printf("max (%d)\n", split->max.size);
	// ft_printf("min (%d)\n", split->min.size);
}

void	splitting_a(t_data *data, t_chunk *chunk)
{
	t_split			split;
	int				pivot;
	int				i;
	int				j;
	static int		flag = 0;

	j = 0;	
	i = 0;
	if (chunk ->size <= 3)
		return (non_rec_routing(data, chunk, &flag));
	pivot = (chunk->size / 2) + find_min(data, chunk);
	while (i < (chunk->size / 2) )
	{
		while (data->stack_a->top->num >= pivot)
		{
			ra(data->stack_a);
			j ++;
		}
		pb(data);
		i ++;
	}
	while (j-- > 0 && flag == 1)
		rra(data->stack_a);
	rec_routing(&split, chunk, i, NULL);
	splitting_a(data, &split.max);
	splitting_b(data, &split.min);
}

void	splitting_b(t_data *data, t_chunk *chunk)
{
	t_split			split;
	int				pivot;
	int				i;
	int				j;
	static int		flag = 0;

	j = 0;	
	i = 0;
	if (chunk ->size <= 3)
		return (non_rec_routing(data, chunk, NULL));
	pivot = find_max(data, chunk) - (chunk->size / 2) ;
	while (i < (chunk->size / 2))
	{
		while (data->stack_b->top->num <= pivot)
		{	
			j ++;
			rb(data->stack_b);
		}
		pa(data);
		i ++;
	}
	while (j-- > 0 && flag == 1)
		rrb(data->stack_b);
	rec_routing(&split, chunk, i, &flag);
	splitting_a(data, &split.max);
	splitting_b(data, &split.min);
}
