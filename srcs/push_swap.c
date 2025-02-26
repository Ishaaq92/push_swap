/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:56:26 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/26 13:31:10 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_data	*create_data(int ac, char *av[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data -> stack_a = malloc(sizeof(t_linked_list));
	data -> stack_b = malloc(sizeof(t_linked_list));
	data -> full_size = 0;
	if (!(data->stack_a) || !(data->stack_b) || ac < 1)
		return (NULL);
	data -> stack_b -> top = NULL;
	data -> stack_b -> bottom = NULL;
	data -> stack_b -> size = 0;
	data -> stack_a ->top = NULL;
	data -> stack_a ->bottom = NULL;
	data -> stack_a ->size = 0;
	parser(data, av);
	return (data);
}

int	main(int ac, char *av[])
{
	t_data			*data;
	t_chunk			start;

	if (ac == 1)
		exit(0);	
	data = create_data(ac, av);
	init_normalise(data);
	if (data->full_size > 5)
	{
		start.loc = TOP_A;
		start.size = data -> stack_a -> size;
		splitting_a(data, &start);
	}
	else
		base_sort(data);
	// print_ll(data);
	free_ll(data, 0);
}
