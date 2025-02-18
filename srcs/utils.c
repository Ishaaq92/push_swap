/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:04:22 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/18 11:14:28 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] != ' ')
			return (i - 1);
	return (-1);
}

int	ft_atoi(t_data *data, const char *nptr, int *index)
{
	int		i;
	int		sign;
	long	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		// Check for overflow before updating total
		if (total * 10 + (nptr[i] - '0') > 2147483647L && sign == 1)
			free_ll(data, 1);
		if (total * 10 + (nptr[i] - '0') > 2147483648L && sign == -1)
			free_ll(data, 1);
		total = total * 10 + (nptr[i++] - '0');
	}
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i ++;
	*index += i;
	return ((int)(total * sign));
}

void	free_ll(t_data *data, int error)
{
	t_node	*node;
	t_node	*temp;

	node = data -> stack_a -> top;
	while (node)
	{
		temp = node -> next;
		free(node);
		node = temp;
	}
	free (data->stack_a);
	node = data -> stack_b -> top;
	while (node)
	{
		temp = node -> next;
		free(node);
		node = temp;
	}
	free (data->stack_b);
	free(data);
	if (error == 1)
		write(2, "Error\n", 6);	
	exit(1);
}

void	print_ll(t_data *data)
{
	t_node			*top;
	t_linked_list	*stack;

	stack = data -> stack_a;
	if (!stack || !(stack->top))
		return ;
	top = stack -> top;
	ft_printf("STACK A \n");
	while (top)
	{
		ft_printf("%d\n", (top)->num);
		top = (top)->next;
	}
	stack = data -> stack_b;
	ft_printf("STACK B\n");
	if (!stack || !(stack->top))
		return ;
	top = stack -> top;
	while (top)
	{
		ft_printf("%d\n", (top)->num);
		top = top ->next;
	}
}
