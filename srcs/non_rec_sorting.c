/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_rec_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:08 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/26 10:41:38 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_a(t_data *data)
{
	int	first;
	int	second;
	int	third;

	if (data->stack_a->size < 3)
		return ;
	first = data->stack_a->top->num;
	second = data->stack_a->top->next->num;
	third = data->stack_a->top->next->next->num;
	if (first > second)
		sa(data->stack_a);
	first = data->stack_a->top->num;
	second = data->stack_a->top->next->num;
	if (first > third || second > third)
	{
		ra(data->stack_a);
		sa(data->stack_a);
		rra(data->stack_a);
	}
	second = data->stack_a->top->next->num;
	third = data->stack_a->top->next->next ->num;
	if (first > second)
		sa(data->stack_a);
}

void	sort_three_b(t_data *data)
{
	pa(data);
	pa(data);
	pa(data);
	sort_three_a(data);
}

void	sort_two_a(t_data *data)
{
	if (data->stack_a->top->num > data->stack_a->top->next->num)
		sa(data->stack_a);
}

void	sort_two_b(t_data *data)
{
	pa(data);
	pa(data);
	sort_two_a(data);
}

void	sort_one(t_data *data, t_chunk *chunk)
{
	if (chunk -> size != 1)
		return ;
	if (chunk ->loc == TOP_B)
		pa(data);
	else if (chunk ->loc == BOTTOM_B)
	{
		rrb(data->stack_b);
		pa(data);
	}
	else if (chunk ->loc == BOTTOM_A)
		rra(data -> stack_a);
}
