#include "../inc/ft_push_swap.h"

void rotate_stack(t_list **stack, char *operation)
{
	rr_helper(stack);
	ft_putendl_fd(operation, 1);
}

void rotate_a_b(t_list **stack_a,t_list **stack_b)
{
	rr_helper(stack_a);
	rr_helper(stack_b);
	ft_putendl_fd("rr", 1);
}