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
	// if (*stack == NULL || (*stack)->next == NULL)
	// 	return;
	// else
	// {
	// 	/* Initialize second last and last pointers */
	// 	t_list *second_last = NULL;
	// 	t_list *last = *stack;

	// 	/*After this loop secLast contains address of second last
	// 	node and last contains address of last node in Linked List */
	// 	while (last->next != NULL)
	// 	{
	// 		second_last = last;
	// 		last = last->next;
	// 	}
	// 	/* Set the next of second last as NULL */
	// 	second_last->next = NULL;
	// 	/* Set next of last as head node */
	// 	last->next = *stack;
	// 	/* Change the head pointer to point to last node now */
	// 	*stack = last;
		rrr_helper(stack);
		ft_putendl_fd(stack_name, 1);
	//}
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

/*
**	This is SA/SB
*/
void	swap_a_b(t_list **stack, char* stack_name)
{
	//printlist(*stack);
	//t_list       *temp;

	//temp = *stack;
	//((t_list *)stack)->next;
	//(struct s_list *)stack = stack->next;
	//temp->next = *stack;
	//*stack = ((t_list *)stack)->next;
	//((t_list *)stack)->next = temp;
	//((t_list *)stack)->next = temp;
	//*stack = temp;

	t_list *tmp1;
	t_list *tmp2;
	t_list *tmp3;

	tmp3 = (*stack)->next->next;
	tmp2 = (*stack)->next;
	tmp1 = *stack;

	*stack = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;






	/*t_list *deki = *stack;
	deki = ((t_list *)stack)->next;
	((t_list *)stack)->next->next = deki->next;*/




	//temp = ((t_list *)stack)->next;
	//stack = ((t_list *)stack)->next;
	//((t_list *)stack)->next = temp;
	//*stack = temp->next->
	//temp = ((t_vars *)((t_list *)stack)->content)->value;
	//temp = ((t_vars *)((t_list *)*stack)->content)->value; ->this works
	//temp = ((t_vars *)(*stack)->content)->value; -> this works
	//temp = ((t_vars **)stack->content)->value;
	//((t_vars *)temporary->content)->value


	//printf("Temp is : %d\n", temp);
	printlist(*stack);


	ft_putendl_fd(stack_name, 1);
}