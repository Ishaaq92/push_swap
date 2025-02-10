/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:56:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/10 13:56:24 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static inline void	swap_private(t_linked_list *stack)
{
	struct s_node	*first;
	struct s_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack -> top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	stack -> top = second;
}

void	sa(t_linked_list *stack)
{
	swap_private(stack);
	ft_printf("sa\n");
}

void	sb(t_linked_list *stack)
{
	swap_private(stack);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	swap_private(data->stack_a);
	swap_private(data->stack_b);
	ft_printf("ss\n");
}
