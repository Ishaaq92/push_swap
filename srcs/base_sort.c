/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:26:40 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/26 16:25:33 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	base_sort_3a(t_linked_list *stack)
{
	int	first;
	int	second;
	int	third;

	if (stack->size != 3)
		return ;
	first = stack->top->num;
	second = stack->top->next->num;
	third = stack->bottom->num;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > third && second < third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	base_sort(t_data *data)
{
	int	i;

	if (check_order(data) == 0)
		return ;
	if ((data->full_size == 4) || (data->full_size == 5))
	{
		i = 0;
		while (i < 2)
		{
			while (data->stack_a->top->num >= 2)
				ra(data->stack_a);
			pb(data);
			i ++;
		}
	}
	if (data->stack_a->size == 3)
		base_sort_3a(data->stack_a);
	else if (data->stack_a->size == 2)
		sort_two_a(data);
	if (data->stack_b->size != 0)
		sort_two_b(data);
}
