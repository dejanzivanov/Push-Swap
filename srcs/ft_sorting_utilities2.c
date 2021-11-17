#include "../inc/ft_push_swap.h"

void rotate_stack(t_list **stack, char *operation)
{
	rr_helper(stack);
	ft_index_update(stack);
	ft_putendl_fd(operation, 1);
}

void rotate_a_b(t_list **stack_a,t_list **stack_b)
{
	rr_helper(stack_a);
	rr_helper(stack_b);
	ft_index_update(stack_a);
	ft_index_update(stack_b);
	ft_putendl_fd("rr", 1);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{

	if (ft_lstsize(*stack_b) == 0)
		return;

	t_list *temp1;
	t_list *temp2;

	temp1 = *stack_b;
	temp2 = (*stack_b)->next;
	temp1->next = *stack_a;
	*stack_b = temp2;
	*stack_a = temp1;
	ft_index_update(stack_a);
	ft_index_update(stack_b);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{

	if (ft_lstsize(*stack_a) == 0)
		return;

	t_list *temp1;
	t_list *temp2;

	temp1 = *stack_a;
	temp2 = (*stack_a)->next;
	temp1->next = *stack_b;
	*stack_b = temp1;
	*stack_a = temp2;
	ft_index_update(stack_a);
	ft_index_update(stack_b);
	ft_putendl_fd("pb", 1);
}

int	ft_min_finder(t_list **stack_a)
{
	// printlist(*stack_a);
	int	index;
	int	min;
	t_list *temp1;
	min = ((t_vars *)(*stack_a)->content)->value;
	index = 0;
	temp1 = NULL;
	temp1 = *stack_a;
	// temp2 = *stack_a;
	while (temp1->next != NULL)
	{
		if (min > (((t_vars *)temp1->next->content)->value))
		{
			min = ((t_vars *)temp1->next->content)->value;
			index = ((t_vars *)temp1->next->content)->index;
			// printf("min =  %d\n", min);
			// printf("index = %d\n", index);
		}

		temp1 = temp1->next;
	}
	// printf("min: %d\n", min);
	// if (min > (((t_vars *)temp1->next->content)->value))
	// {
	// printf("inside if: %d\n", min);
	// 	min = ((t_vars *)temp1->content)->value;
	// 	printf("inside2 if: %d\n", min);
	// 	counter += 1;
	// }
	// *stack_a = temp2;
	// int	index;
	// int	min;
	// t_list *temp1;
	// min = ((t_vars *)(*stack_a)->content)->value;
	// printf("min = %d\n", min);
	// index = 0;
	// temp1 = *stack_a;
	// // temp2 = *stack_a;
	// printf("TEST LOL?\n");
	// while (temp1->next != NULL)
	// {
	// 	if (min > (((t_vars *)temp1->next->content)->value))
	// 	{
	// 		min = ((t_vars *)temp1->next->content)->value;
	// 		index += 1;
	// 		printf("min =  %d\n", min);
	// 		printf("index = %d\n", index);
	// 	}
	// 	else
	// 		index += 1;

	// 	temp1 = temp1->next;
	// }
	return (index);
}


//pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.