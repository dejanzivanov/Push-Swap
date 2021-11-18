#include "../inc/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc <= 2)
	{
		ft_free_list(stack_a);
		exit(1);
	}
	stack_a = ft_error_handler(argv, stack_a);
	ft_argument_check(argv, &stack_a, &stack_b);
	return (0);
}

/*
**	List of Actions
**
**	sa : swap a - swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements).
**
**	sb : swap b - swap the first 2 elements at the top of stack b.
**	Do nothing if there is only one or no elements).
**
**	ss : sa and sb at the same time.
**
**	pa : push a - take the first element at the top of b and put it at the top
**	of a. Do nothing if b is empty.
**
**	pb : push b - take the first element at the top of a and put it at the top
**	of b. Do nothing if a is empty.
**
**	ra : rotate a - shift up all elements of stack a by 1.
**	The first element becomes the last one.
**
**	rb : rotate b - shift up all elements of stack b by 1.
**	The first element becomes the last one.
**
**	rr : ra and rb at the same time.
**
**	rra : reverse rotate a - shift down all elements of stack a by 1.
**	The last element becomes the first one.
**
**	rrb : reverse rotate b - shift down all elements of stack b by 1.
**	The last element becomes the first one.
**
**	rrr : rra and rrb at the same time.
**
**	Helping Commands
**
**	PROMPT_DIRTRIM=1 - helping command for shortening the terminal directory
**
**	clear
**	make
**	ARG=`ruby -e 'puts (1000..1004).to_a.shuffle.join(" ")'`;
**	clear
**	#valgrind ./push_swap $ARG
**	./push_swap $ARG
**	# ./push_swap $ARG | wc -l
**	echo $ARG
*/