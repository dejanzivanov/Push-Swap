#include "../inc/ft_push_swap.h"

void reverse(char *x, int begin, int end)
{
   char c;

   if (begin >= end)
      return;

   c          = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end)   = c;

   reverse(x, ++begin, --end);
}

int		ft_check_base(char *base, int base_len, int i, int index)
{
	int ret_val;

	ret_val = 1;
	if (base_len < 2)
		return (0);
	while (i + index < base_len)
	{
		if (base[i] == base[i + index] || base[i] == '+' || base[i] == '-'
			|| base[i + 1] == '+' || base[i + 1] == '-')
			return (0);
		else
			ret_val = ret_val * ft_check_base(base, base_len, i, index + 1);
		i++;
	}
	return (ret_val);
}

int	ft_print_base(int nbr, char *base, int base_len)
{
	int counter;

	counter = 1;
	//printf("1Counter is : %d\n", counter);
	//printf("nbr / base_len : %d\n", nbr / base_len );
	if (nbr / base_len)
	{
		counter = counter + ft_print_base(nbr / base_len, base, base_len);
	}
	//printf("2Counter is : %d\n", counter);
	//return (base[nbr % base_len]);
	//return (base[nbr % base_len]);
	return counter;
}

void	ft_print_base2(int nbr, char *base, int base_len, char *str, int i)
{
	int counter;

	counter = 1;
	if (nbr / base_len > 0)
	{
		//str[i] = *ft_itoa(nbr % base_len);
		//printf("And this madafaka is %c\n", str[i]);
		ft_print_base2(nbr / base_len, base, base_len, str, i + 1);
	}
	str[i] = *ft_itoa(nbr % base_len);
	//return (base[nbr % base_len]);
	//return (base[nbr % base_len]);
}

char	*ft_put_nbrbase(int nbr, char *base)
{
	int base_len;
	char *str;
	int	value;

	base_len = ft_strlen(base);

	if (ft_check_base(base, base_len, 0, 1))
	{
		value = ft_print_base(nbr, base, base_len);
	}
	str = ft_calloc(sizeof(value) + 1, 1);
	ft_print_base2(nbr, base, base_len, str, 0);

	reverse(str, 0, ft_strlen(str)-1);
	//printf("String is %s \n", str);
	return str;
}

//ft_put_nbrbase(-50, "01");


void swap1(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap1(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
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
	printlist(stack_a);
	values = ft_calloc(ft_lstsize(stack_a), sizeof(int));
	counter = stack_a;
	//printf("Size list is: %d", ft_lstsize(stack_a));
	//printf("Counter is: %d\n", ft_lstsize(counter));
	while (i < ft_lstsize(stack_a))
	{
		values[i] = ((t_vars *)(*counter).content)->value;
		counter = (*counter).next;
		i++;
	}
	//printf("Counter is: %d\n", ft_lstsize(counter));
	bubbleSort(values, i);
	//printf("Sorted array: \n");
	//printf("Size list is: %d\n", ft_lstsize(counter));
	//printf("Arraj value is %d", values[4]);


	while (j  < i )
	{	counter = stack_a;
		while (counter)
		{
			if (values[j] == ((t_vars *)(*counter).content)->value)
			{
				((t_vars *)(*counter).content)->sorted_index = j;
				printf("J is : %d and index is %d \n", j , ((t_vars *)(*counter).content)->sorted_index);
				((t_vars *)(*counter).content)->bin_num = ft_put_nbrbase(j, "01");
			}

			counter = (*counter).next;
		}
		j++;
	}

	counter = stack_a;

	 //printf("Array print ");
	 //printArray(values, i);
	while (counter != NULL)
	{
		//printf("Sorted Index is %d -> \n", ((t_vars *)counter->content)->sorted_index);
		//printf("Value        is %d -> \n", ((t_vars *)counter->content)->value);
		printf("Value        is %s -> \n", ((t_vars *)counter->content)->bin_num);
		counter = counter->next;
	}






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