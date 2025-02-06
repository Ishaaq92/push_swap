/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:56:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/06 12:26:23 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int push(t_linked_list *stack_a, t_linked_list *stack_b, char c)
{
	t_node *node;
	
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


void pb(t_data *data)
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

static inline void swap_private(t_linked_list *stack)
{
	struct s_node *first;
	struct s_node *second;

	if (!stack || !stack->top || !stack->top->next)
		return; 
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

void sa(t_linked_list *stack)
{
	swap_private(stack);
	ft_printf("sa\n");
}
void sb(t_linked_list *stack)
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

void	rotate_private(t_linked_list *stack)
{
	t_node *top_node;
	t_node	*top;
	t_node	*bottom;

	top = stack -> top;
	bottom = stack -> bottom;
	if (!stack || !top || !bottom ||top == bottom)
		return;
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

static inline void	reverse_rotate_private(t_linked_list *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (!stack || !(stack->top) || !(stack->bottom) || stack->size < 2)
		return ;
	top = stack -> top;
	bottom = stack -> bottom;

	// Disconnecting from bottom.
	bottom -> previous -> next = NULL;
	stack -> bottom = bottom -> previous; 
	bottom ->previous = NULL;

	// Connect to top.
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
