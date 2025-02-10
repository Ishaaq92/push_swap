/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:49:51 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/10 13:58:23 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_linked_list *stack_a, t_linked_list *stack_b, char c)
{
	t_node	*node;

	if (!stack_a || !stack_a->top)
		return (0);
	node = stack_a->top;
	stack_a->top = node->next;
	if (stack_a->top)
		stack_a->top->previous = NULL;
	else
		stack_a->bottom = NULL;
	node->next = stack_b->top;
	if (stack_b->top)
		stack_b->top->previous = node;
	else
		stack_b->bottom = node;
	stack_b->top = node;
	if (c == 'A')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	return (1);
}

void	pb(t_data *data)
{
	if (push(data->stack_a, data->stack_b, 'B') == 0)
		return ;
	data -> stack_a->size--;
	data -> stack_b->size++;
}

void	pa(t_data *data)
{
	if (push(data->stack_b, data->stack_a, 'A') == 0)
		return ;
	data -> stack_a->size++;
	data -> stack_b->size--;
}
