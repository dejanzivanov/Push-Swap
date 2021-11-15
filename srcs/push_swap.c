//#include "inc/ft_push_swap.h"
#include "../inc/ft_push_swap.h"

void insert(t_list **b, void *content)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	node->content = content;
	node->next = *b;
	*b = node;
}

t_list *copy_list(t_list *head)
{
	if (head == NULL)
		return NULL;
	else
	{
		t_list *newNode;
		newNode = (t_list *)malloc(sizeof(t_list));
		newNode->content = head->content;
		newNode->next = copy_list(head->next);
		return (newNode);
	}


}

int main(int argc, char **argv)
{
	//adding test commit
	//commit test of deki branch

	/*int i;
	int j;

	i = 1;
	j = 0;*/

	//printf("we are here\n and number of arguments %d and %s", argc, argv[0]);
	/*while (i < argc)
	{
		//printf("%s ", argv[i]);
		//printf("String is: %s ", argv[i]);
		j = ft_atoi(argv[i]);

		printf("%d", j);
		i++;
	}*/
	//printf("%s", argv[1]);
	//if (argc == 1 || argc == 2)
	/*printf("%s", argv[0]);
	printf("%s", argv[1]);
	exit(EXIT_SUCCESS);*/



	t_list *stack_a;

	t_list *stack_b;

	//stack_a = (t_list *)ft_calloc(1, sizeof(t_list));
	stack_a = NULL;

	if (argc <= 2)
	{
		freeList(stack_a);
		exit(1);
	}

	stack_a = ft_error_handler(argv, stack_a);
	stack_b = copy_list(stack_a);
	printlist(stack_a);
	swap_a_b(&stack_a, "sa");
	//printlist(stack_b);

	//reverse_rotate_a_b(&stack_a, &stack_b);
	//printlist(stack_a);
	//printlist(stack_b);
	//reve
	//printf("\n");
	//printlist(stack_b);

	//reverse_rotate_stack(&stack_a, "rra");
	//printlist(stack_a);
	//reverse_rotate_stack(&stack_a, "rra");
	//printlist(stack_a);
	//printlist(stack_a);


	//printlist(stack_a);
	//ft_argument_check(argv, stack_a);
	//printf("Giberish %d\n", ((t_vars *)stack_a->content)->value);

	//printf("STACK A IS ->  %d", ((t_vars *)stack_a->content)->value);
	//free(stack_a);

	/*start_push(swap)



	//WE HAVE 4 TEST CASES
	3 - 5 IFS - HARDCODED 5 IFS -> 2-3 ACTIONS SECOND

	5 - 5 + IDK - ????
	100 - ???
	500 - ???


	if(number of test cases3) - first testac
		start1
	101   	5 	0
	5 		0 	101
	0 		5 	101
	x 		y 		z
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		z = ft_atoi(argv[3]);
		if (x > y) && (x > z)
		{
			ra(elements);
			if (y > z)
				sa(y, z);
			else
				-> return the arranged stack
		}
		if()
		if()
		if()
		if()
		if()
	if(number of test cases5)
		start2
	if(number of test cases100)
		start3
	if(number of test cases500)
		start4*/


	return (0);

}

// REMINDER INITIALIZE THE LINKED LIST AT THE START OF THE MAIN SO ITS USABLE FOR LATER



// PROMPT_DIRTRIM=1 - helping command for shortening the terminal directory


//clear | make | ARG=`ruby -e 'puts (0..3).to_a.shuffle.join(" ")'`; ./push_swap $ARG

// ARG=`ruby -e 'puts (1..50).to_a.shuffle.join(" ")'`; ./push_swap $ARG

/*
**	git branch deki - Create Branch
**	git checkout deki - Set a branch as a working directory
**	git push -u origin deki - Push Changes to your Branch
**	Change "deki" - with your branch
*/

/*
**	Already Sorted
**	Errong Handling / No Arguments
**	Establish the rules
**
**	sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
**	sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
**	ss` : sa and sb at the same time.
**	pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
**	pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
**	ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
**	rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
**	rr : ra and rb at the same time.
**	rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
**	rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
**	rrr : rra and rrb at the same time.
**
*/
