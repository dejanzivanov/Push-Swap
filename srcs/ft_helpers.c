#include "../inc/ft_push_swap.h"

void	rrr_helper(t_list **stack)
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
	}
}

void swap_helper(t_list **stack)
{
		t_list *tmp1;
	t_list *tmp2;
	t_list *tmp3;

	tmp3 = (*stack)->next->next;
	tmp2 = (*stack)->next;
	tmp1 = *stack;

	*stack = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
}
