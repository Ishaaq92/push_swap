/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:37 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/03 11:58:11 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*add_node(int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return NULL;
	new_node->num = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void append_node(t_linked_list *stack, int val)
{
	t_node *node;
	
	node = add_node(val);
	if (!node)
		return;
	if (!(stack->top)) // If the stack is empty
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->previous = stack->bottom;
		stack->bottom = node;
	}
	stack ->size ++;
}

t_linked_list	*parser(int ac, char *av[])
{
	int				i;
	int				j;
	t_node			*node;
	t_linked_list	*stack;

	i = 1;
	stack = malloc(sizeof(t_linked_list));
	if (!stack)
		return (NULL);	
	stack ->top = NULL;
	stack ->bottom = NULL;
	stack ->size = 0;
	while (av[i] != 0)
	{
		if (is_empty(av[i]) == -1)
		{
			i ++;
			continue;
		}
		j = 0;
		while (av[i][j] != '\0')
			append_node(stack, ft_atoi(&av[i][j], &j));
		i ++;
	}
	return (stack);
}


