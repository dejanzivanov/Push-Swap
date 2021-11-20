#include "../inc/ft_push_swap.h"

void	ft_handle_two(t_list **stack_a)
{
	int	i;
	int	j;

	i = ((t_vars *)(*stack_a)->content)->value;
	j = ((t_vars *)(*stack_a)->next->content)->value;
	if (i > j)
		swap(stack_a, "sa");
}

void	ft_handle_three(t_list **stack_a)
{
	int	i[3];

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
}

void	ft_handle_four(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = ft_min_finder(stack_a);
	if (index == 0)
		push_b(stack_a, stack_b);
	else if (index == 1)
	{
		rotate_stack(stack_a, "ra");
		push_b(stack_a, stack_b);
	}
	else if (index == 2)
	{
		reverse_rotate_stack(stack_a, "rra");
		reverse_rotate_stack(stack_a, "rra");
		push_b(stack_a, stack_b);
	}
	else if (index == 3)
	{
		reverse_rotate_stack(stack_a, "rra");
		push_b(stack_a, stack_b);
	}
	ft_handle_three(stack_a);
	push_a(stack_a, stack_b);
}

void	ft_handle_five(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = ft_min_finder(stack_a);
	if (index == 0)
		push_b(stack_a, stack_b);
	else if (index == 1)
	{
		rotate_stack(stack_a, "ra");
		push_b(stack_a, stack_b);
	}
	else if (index == 2)
	{
		rotate_stack(stack_a, "rra");
		rotate_stack(stack_a, "rra");
		push_b(stack_a, stack_b);
	}
	else if (index == 3)
		ft_reverse_rotate_helper(stack_a, stack_b);
	else
	{
		reverse_rotate_stack(stack_a, "rra");
		push_b(stack_a, stack_b);
	}
	ft_handle_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

int	ft_is_sorted(t_list **stack_a)
{
	t_list	*temporary;
	int		values[3];

	temporary = *stack_a;
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	while (temporary != NULL)
	{
		values[0] = ((t_vars *)temporary->content)->value;
		temporary = temporary->next;
		if (temporary != NULL)
			values[1] = ((t_vars *)temporary->content)->value;
		if (temporary != NULL)
		{
			if (!(values[0] < values[1]))
				values[2]++;
		}
	}
	if (values[2] == 0)
		return (1);
	else
		return (0);
}
