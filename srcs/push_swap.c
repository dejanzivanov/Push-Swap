#include "../inc/ft_push_swap.h"

void	ft_swap1(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	ft_bubble_sort(int arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap1(&arr[j], &arr[j + 1]);
			j += 1;
		}
		i += 1;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*values;
	int		i;
	int		j;
	t_list	*counter;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	j = 0;
	if (argc <= 2)
	{
		ft_free_list(stack_a);
		exit(1);
	}
	stack_a = ft_error_handler(argv, stack_a);
	values = ft_calloc(ft_lstsize(stack_a), sizeof(int));
	counter = stack_a;
	while (i < ft_lstsize(stack_a))
	{
		values[i] = ((t_vars *)(*counter).content)->value;
		counter = (*counter).next;
		i++;
	}
	ft_bubble_sort(values, i);
	while (j < i)
	{
		counter = stack_a;
		while (counter)
		{
			if (values[j] == ((t_vars *)(*counter).content)->value)
			{
				((t_vars *)(*counter).content)->sorted_index = j;
				((t_vars *)(*counter).content)->bin_num
					= ft_put_nbrbase(j, "01");
			}
			counter = (*counter).next;
		}
		j++;
	}
	counter = stack_a;
	while (counter != NULL)
		counter = counter->next;
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