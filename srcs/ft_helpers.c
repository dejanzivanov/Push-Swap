#include "../inc/ft_push_swap.h"

void	rrr_helper(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;

	second_last = NULL;
	last = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	else
	{
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	swap_helper(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp3 = (*stack)->next->next;
	tmp2 = (*stack)->next;
	tmp1 = *stack;
	*stack = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
}

/*
**	FIRST ELEM BECOMES LAST
*/

void	rr_helper(t_list **stack)
{
	t_list	*second;
	t_list	*third;
	t_list	*first;

	second = (*stack)->next;
	third = (*stack)->next;
	first = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	else
	{
		first->next = NULL;
		while (second->next != NULL)
			second = second->next;
		second->next = first;
		*stack = third;
	}
}

void	ft_reverse_rotate_helper(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack(stack_a, "rra");
	reverse_rotate_stack(stack_a, "rra");
	push_b(stack_a, stack_b);
}
