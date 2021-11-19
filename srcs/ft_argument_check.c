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
	else if (argument_num > 5 && argument_num <= 100)
		ft_handle_hundred(stack_a, stack_b);
	else if (argument_num > 100)
		ft_handle_five_hundred();
}
