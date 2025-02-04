/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_rec_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:08 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/04 14:21:49 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_a(t_data *data)
{
	int first, second, third;
	t_linked_list *a = data->stack_a;

	if (a->size < 3)
		return;
	first = a->top->num;
	second = a->top->next->num;
	third = a->top->next->next->num;
	if (first > second && second > third) // 3 2 1 -> 1 2 3
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sa(a);	
	}
	else if (first > third && third > second) // 3 1 2 -> 1 2 3
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
	}
	else if (second < first && first < third) // 2 1 3 -> 1 2 3
		sa(a);
	else if (second > third && third < first) // 2 3 1 -> 1 2 3
	{
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
	else if (third > first && first < second && second > third) // 1 3 2 -> 1 2 3
	{
		ra(a);	
		sa(a);
		rra(a);
	}
}
void	sort_three_b(t_data *data)
{	
	// Pushes to stack A 
	// Then sorts them.
	pa(data);
	ft_printf("HERE!!-\n");
	pa(data);
	pa(data);
	sort_three_a(data);
}

void	sort_two_a(t_data *data)
{
	t_linked_list	*stack;
	int				first;
	int				second;	

	first = data->stack_a->top->num;	
	second = data->stack_a->top->next->num;
	if (first > second)
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
		rra(data ->stack_a);
}