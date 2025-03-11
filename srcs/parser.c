/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:37 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/11 10:29:52 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*add_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	append_node(t_linked_list *stack, int val)
{
	t_node	*node;

	node = add_node(val);
	if (!node)
		return ;
	if (!(stack->top))
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

void	skip_white_space(char *av[], int i, int *index)
{
	int	j;

	j = (*index);
	while (((av[i][j] >= 9 && av[i][j] <= 13) ||
	av[i][j] == ' ') && av[i][j] != '\0')
		j++;
	(*index) = j;
}

void	parser(t_data *data, char *av[])
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	skip_white_space(av, i, &j);
	while (av[++i] != 0)
	{
		if (is_empty(av[i]) == -1)
			free_ll(data, 1);
		j = 0;
		while (av[i][j] != '\0')
		{
			skip_white_space(av, i, &j);
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				if ((av[i][j] != '+' && av[i][j] != '-') ||
				!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
					free_ll(data, 1);
			append_node(data->stack_a, ft_atoi(data, &av[i][j], &j));
			if (!(av[i][j] >= 9 && av[i][j] <= 13) &&
			(av[i][j] != ' ') && av[i][j] != '\0')
				free_ll(data, 1);
			skip_white_space(av, i, &j);
		}
	}
}
