/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:54:06 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/10 13:58:50 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_private(t_linked_list *stack)
{
	t_node	*top_node;
	t_node	*top;
	t_node	*bottom;

	top = stack -> top;
	bottom = stack -> bottom;
	if (!stack || !top || !bottom || top == bottom)
		return ;
	top_node = top;
	stack -> top = top->next;
	top->previous = NULL;
	top_node->next = NULL;
	top_node->previous = bottom;
	bottom->next = top_node;
	stack ->bottom = top_node;
}

void	ra(t_linked_list *stack_a)
{
	rotate_private(stack_a);
	ft_printf("ra\n");
}

void	rb(t_linked_list *stack_b)
{
	rotate_private(stack_b);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	rotate_private(data->stack_a);
	rotate_private(data->stack_b);
	ft_printf("rr\n");
}
