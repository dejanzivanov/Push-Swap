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
		printlist(*stack_a);

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

	printlist(*stack_a);


	//printf("Starting to sort 3 arguments\n");
}

void ft_handle_four(void)
{
	printf("Starting to sort 4 arguments\n");
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

