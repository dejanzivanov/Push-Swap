#include "../inc/ft_push_swap.h"

void	ft_argument_check(char **argv, t_list **stack_a, t_list **stack_b)
{
	int	argument_num;

	argument_num = ft_lstsize(*stack_a);
	if (argument_num == 2)
		ft_handle_two(stack_a);
	else if (argument_num == 3)
		ft_handle_three(stack_a);
	else if (argument_num == 4)
		ft_handle_four(stack_a, stack_b);
	else if (argument_num == 5)
		ft_handle_five(stack_a, stack_b);
	else if (argument_num > 5)
		ft_handle_hundred(stack_a, stack_b);
}

void	ft_sorting_helper(t_list **s_a, t_list **s_b, int i)
{
	int	nav;
	int	counter;

	counter = ft_lstsize(*s_a);
	nav = 0;
	while (nav < counter)
	{
		if ((((t_vars *)(*s_a)->content)->sorted_index) >> i & 1 == 1)
			rotate_stack(s_a, "ra");
		else
			push_b(s_a, s_b);
		nav += 1;
	}
}

int	ft_get_bits(t_list **stack_a)
{
	t_list	*temp;
	int		max;
	int		bits;

	bits = 0;
	temp = *stack_a;
	max = ((t_vars *)(temp)->content)->value;
	while (temp->next != NULL )
	{
		if (max < ((t_vars *)(temp)->next->content)->value)
			max = ((t_vars *)(temp)->next->content)->value;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	bits++;
	return (bits);
}

void	ft_handle_hundred(t_list **stack_a, t_list **stack_b)
{
	int		nav;
	int		bits;
	int		i;
	int		counter;

	counter = 0;
	bits = ft_get_bits(stack_a);
	nav = 0;
	i = 0;
	while (i < bits)
	{
		ft_sorting_helper(stack_a, stack_b, i);
		nav = 0;
		counter = ft_lstsize(*stack_b);
		while (nav < counter)
		{
			push_a(stack_a, stack_b);
			nav += 1;
		}
		if (ft_is_sorted(stack_a) == 1)
			break ;
		i++;
	}
}
