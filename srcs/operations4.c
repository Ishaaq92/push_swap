/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:57:01 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/10 14:01:09 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static inline void	reverse_rotate_private(t_linked_list *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (!stack || !(stack->top) || !(stack->bottom) || stack->size < 2)
		return ;
	top = stack -> top;
	bottom = stack -> bottom;
	bottom -> previous -> next = NULL;
	stack -> bottom = bottom -> previous;
	bottom -> previous = NULL;
	bottom -> next = top;
	top -> previous = bottom;
	stack -> top = bottom;
}

void	rra(t_linked_list *stack_a)
{
	reverse_rotate_private(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_linked_list *stack_b)
{
	reverse_rotate_private(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	reverse_rotate_private(data->stack_a);
	reverse_rotate_private(data->stack_b);
	ft_printf("rrr");
}
