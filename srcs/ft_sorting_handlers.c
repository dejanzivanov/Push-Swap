#include "../inc/ft_push_swap.h"

void ft_handle_two(t_list **stack_a)
{
	printlist(*stack_a);
	int	i;
	int	j;

	i = ((t_vars *)(*stack_a)->content)->value;
	j = ((t_vars *)(*stack_a)->next->content)->value;
	if (i > j)
		swap(stack_a, "sa");

	//printf("Starting to sort 2 arguments\n");
}

void ft_handle_three(t_list **stack_a)
{
		// printlist(*stack_a);

	int i[3];

	i[0] = ((t_vars *)(*stack_a)->content)->value;
	i[1] = ((t_vars *)(*stack_a)->next->content)->value;
	i[2] = ((t_vars *)(*stack_a)->next->next->content)->value;

	if ((i[0] > i[1]) && (i[0] > i[2]))
	{
		rotate_stack(stack_a, "ra");
		if (i[1] > i[2])
			swap(stack_a, "sa");

	}
	else if ((i[1] > i[0]) && (i[1] > i[2]))
	{
		reverse_rotate_stack(stack_a, "rra");
		if (i[2] > i[0])
			swap(stack_a, "sa");
	}
	else if ((i[2] > i[0]) && (i[2] > i[1]))
	{
		if ((i[0] > i[1]))
			swap(stack_a, "sa");
	}


	//free(i[0]);


	/*int i;
	int j;
	int k;

	i = ((t_vars *)(*stack_a)->content)->value;
	j = ((t_vars *)(*stack_a)->next->content)->value;
	k = ((t_vars *)(*stack_a)->next->next->content)->value;

	if ((i > j) && (i > k))
	{
		rotate_stack(stack_a, "ra");
		if (j > k)
			swap(stack_a, "sa");

	}
	else if ((j > i) && (j > k))
	{
		reverse_rotate_stack(stack_a, "rra");
		if (k > i)
			swap(stack_a, "sa");
	}*/

	// printlist(*stack_a);


	//printf("Starting to sort 3 arguments\n");
}

void ft_handle_four(t_list **stack_a, t_list **stack_b)
{
	int	counter;
	// int i[4];
	// t_list *temp1;
	// t_list *temp2;
	// i[0] = ((t_vars *)(*stack_a)->content)->value;
	// i[1] = ((t_vars *)(*stack_a)->next->content)->value;
	// i[2] = ((t_vars *)(*stack_b)->next->content)->value;
	// i[3] = ((t_vars *)(*stack_a)->next->content)->value;

	// push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	counter = ft_min_finder(stack_a);
	// int	min;

	// t_list *temp1;
	// t_list *temp2;

	// min = ((t_vars *)(*stack_a)->content)->value;
	// counter = 0;
	// temp1 = *stack_a;
	// temp2 = *stack_a;
	// while (temp1->next != NULL)
	// {
	// 	if (min > ((t_vars *)(*stack_a)->content)->value)
	// 	{
	// 		min = ((t_vars *)(*stack_a)->content)->value;
	// 		counter += 1;
	// 	}
	// 	temp1 = temp1->next;
	// }
	// min = 0;
	// *stack_a = temp2;

	if (counter == 0)
		push_b(stack_a, stack_b);
	else if (counter == 1)
	{
		rotate_stack(stack_a, "ra");
		push_b(stack_a, stack_b);
	}
	else if (counter == 2)
	{
		reverse_rotate_stack(stack_a, "rra");
		reverse_rotate_stack(stack_a, "rra");
		push_b(stack_a, stack_b);
	}
	else
	{
		reverse_rotate_stack(stack_a, "rra");
		push_b(stack_a, stack_b);
	}
	ft_handle_three(stack_a);
	push_a(stack_a, stack_b);
	
}

void ft_handle_five(void)
{
	printf("Starting to sort 5 arguments\n");
}

void ft_handle_hundred(void)
{
	printf("Starting to sort 100 arguments\n");
}

void ft_handle_five_hundred(void)
{
	printf("Starting to sort 100+ arguments\n");
}

