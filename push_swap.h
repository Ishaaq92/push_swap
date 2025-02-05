/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:58:05 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/05 11:37:26 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>

enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
};

typedef struct s_node
{
	int             num;
	struct s_node   *next;
	struct s_node   *previous;
} t_node;

typedef struct linked_list
{
	t_node *top;
	t_node *bottom;
	int		size;
} t_linked_list;

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
} t_chunk;

typedef struct s_split
{
	t_chunk	max;
	t_chunk	min;
} t_split;

typedef struct s_data
{
	t_linked_list	*stack_a;
	t_linked_list	*stack_b;
} t_data;

// Parser
t_linked_list	*parser(int ac, char *av[]);

// Normalisation
void			init_normalise(t_data *data);
int				find_max(t_data *data, t_chunk *chunk);
int				find_min(t_data *data, t_chunk *chunk);

// Non_Rec_Sorting
void			sort_three_a(t_data *data);
void			sort_three_b(t_data *data);
void			sort_two_a(t_data *data);
void			sort_two_b(t_data *data);
void			sort_one(t_data *data, t_chunk *chunk);

// Rec_Sorting
void			splitting_a(t_data *data, t_chunk *chunk);
void			splitting_b(t_data *data, t_chunk *chunk);

// Utils
int				ft_atoi(const char *nptr, int *index);
void			print_ll(t_data *data);
void			free_ll(t_data *data);
int				is_empty(char *str);

// Operations
void			sa(t_linked_list *stack);
void			sb(t_linked_list *stack);
void			ss(t_data *data);

void			pa(t_data *data);
void			pb(t_data *data);

void			ra(t_linked_list *stack);
void			rb(t_linked_list *stack);
void			rr(t_data *data);

void			rra(t_linked_list *stack_a);
void			rrb(t_linked_list *stack_b);
void			rrr(t_data *data);

int push(t_linked_list *stack_a, t_linked_list *stack_b, char c);

#endif