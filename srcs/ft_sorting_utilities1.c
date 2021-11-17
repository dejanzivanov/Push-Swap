#include "../inc/ft_push_swap.h"

/*
**	Reverse Rotate B - RRB shift down all elements of stack b by 1.
**	The last element becomes the first one.
*/

/*
**	Reverse Rotate A - RRA shift down all elements of stack a by 1.
**	The last element becomes the first one.
*/

/*
**	Only difference between RRB and RRA is print output
**	and stack provided to function.
*/
void	reverse_rotate_stack(t_list **stack, char *operation)
{
	rrr_helper(stack);
	ft_index_update(stack);
	ft_putendl_fd(operation, 1);
}


/*
**	This is RRR
*/
void	reverse_rotate_a_b(t_list **stack_a,t_list **stack_b)
{
	rrr_helper(stack_a);
	rrr_helper(stack_b);
	ft_index_update(stack_a);
	ft_index_update(stack_b);
	ft_putendl_fd("rrr", 1);

}

/*
**	This is SA/SB
*/
void	swap(t_list **stack, char* operation)
{
	swap_helper(stack);
	ft_index_update(stack);
	ft_putendl_fd(operation, 1);
}

/*
**	This is SS
*/
void swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_helper(stack_a);
	swap_helper(stack_b);
	ft_index_update(stack_a);
	ft_index_update(stack_b);
	ft_putendl_fd("ss", 1);
}