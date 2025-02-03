#include "../push_swap.h"


void	sort_three_b(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	int				first;
	int				second;
	int				third;
	
	stack = data -> stack_b;
	first = stack->top->num;
	second = stack->top->next->num;
	third = stack->top->next->next->num;
	if (first < second && second < third) // Case: 1 2 3 -> 3 2 1
	{
		sb(stack);
		rrb(stack);
	}
	else if (first < third && third < second) // Case: 1 3 2 -> 3 2 1
		rrb(stack);
	else if (second < first && first < third) // Case: 2 1 3 -> 3 2 1
		rb(stack);
	else if (second < third && third < first) // Case: 2 3 1 -> 3 2 1
	{
		sb(stack);
		rb(stack);
	}
	else if (third < first && first < second) // Case: 3 1 2 -> 3 2 1
		sb(stack);
}

void	sort_three_a(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	int				first;
	int				second;
	int				third;
	
	stack = data->stack_a; 
	first = stack->top->num;
	second = stack->top->next->num;
	third = stack->top->next->next->num;
	if (first > second && second > third) // Case: 3 2 1 -> 1 2 3
	{
		sb(stack);
		rrb(stack);
	}
	else if (first > third && third > second) // Case: 3 1 2 -> 1 2 3
		rb(stack);
	else if (second > first && first > third) // Case: 2 3 1 -> 1 2 3
	{
		sb(stack);
		rb(stack);
	}
	else if (second > third && third > first) // Case: 2 1 3 -> 1 2 3
		sb(stack);
	else if (third > first && first > second) // Case: 1 3 2 -> 1 2 3
		rrb(stack);
}

void	sort_two_b(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	int				first;
	int				second;	

	if (chunk->size != 2)
		return ;
	first = data->stack_b->top->num;	
	second = data->stack_b->top->next->num;
	if (first < second)
		sb(data->stack_b);
}

void	sort_two_a(t_data *data, t_chunk *chunk)
{
	t_linked_list	*stack;
	int				first;
	int				second;	

	if (chunk->size != 2)
		return ;
	first = data->stack_a->top->num;	
	second = data->stack_a->top->next->num;
	if (first > second)
		sa(data->stack_a);
}

void	sort_one(t_data *data, t_chunk *chunk)
{
	if (chunk -> size != 1)
		return ;
	if (chunk ->loc == TOP_B)
		pa(data);
	else if (chunk ->loc == BOTTOM_B)
	{
		rrb(data->stack_b);
		pa(data);
	}
	else if (chunk ->loc == BOTTOM_A)
		rra(data ->stack_a);
}