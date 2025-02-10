/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:56:26 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/10 14:42:34 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_data	*create_data(int ac, char *av[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data -> stack_a = parser(ac, av);
	data -> stack_b = malloc(sizeof(t_linked_list));
	data -> stack_b -> top = NULL;
	data -> stack_b -> bottom = NULL;
	data ->stack_b -> size = 0;
	return (data);
}

int	main(int ac, char *av[])
{
	t_data			*data;
	t_chunk			start;

	data = create_data(ac, av);
	init_normalise(data);
	start.loc = TOP_A;
	start.size = data -> stack_a -> size;
	splitting_a(data, &start);
	free_ll(data);
}
