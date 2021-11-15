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

void	reverse_rotate_stack(t_list **stack, char *stack_name)
{
	//printlist(*stack_b);
	//ft_lstadd_front(*stack_b, &stack_b);

	 /* If linked list is empty, or it contains only one node,
      then nothing needs to be done, simply return */
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	else
	{
		/* Initialize second last and last pointers */
		t_list *second_last = NULL;
		t_list *last = *stack;

		/*After this loop secLast contains address of second last
		node and last contains address of last node in Linked List */
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		/* Set the next of second last as NULL */
		second_last->next = NULL;
		/* Set next of last as head node */
		last->next = *stack;
		/* Change the head pointer to point to last node now */
		*stack = last;
		ft_putendl_fd(stack_name, 1);
	}
}


/*
**	This is RRR
*/
void	reverse_rotate_a_b(t_list **stack_a,t_list **stack_b)
{
	rrr_helper(stack_a);
	rrr_helper(stack_b);
	ft_putendl_fd("rrr", 1);

}