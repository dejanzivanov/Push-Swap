#include "../inc/ft_push_swap.h"

void printlist(t_list *head)
{
	t_list *temporary = head;
	int i = 0;

	while (temporary != NULL)
	{
		//printf("INDEX IS : %d \n", *(temporary)->content->value);
		//printf("INDEX IS : %d \n", *(*(temporary->content))->index);
		//printf("VALUE IS : %d \n", (*(t_list *)temporary)->(t_vars *)content->value);
		printf("VALUE IS : %d \n \n", ((t_vars *)temporary->content)->value);
		printf("INDEX    : %d \n", ((t_vars *)temporary->content)->index);
		//printf("idfag %d\n", head->(t_vars *)content->value);
		//printf("idfag %d\n", ((t_list *)head)->content.value);
		//printf("idfag %d\n", ((t_list *)head)->content->value);
		//printf("idfag %d\n", ((t_list *)head)->((t_vars *)content)->value);
		temporary = temporary->next;
		//printf("I is: %d\n", i);
		i++;
	}
	printf("\n");


}


void check_if_sorted_list_is_sorted(t_list *head)
{
	t_list *temporary = head;
	int value1;
	int value2;
	int sorted;

	value1 = 0;
	value2 = 0;
	sorted = 0;

	//printf("Data is: %p", temporary->content);


	//printf("VALUE IS : %d \n", ((t_vars *)temporary->content)->value);
	while (temporary != NULL)
	{
		//value1 = temporary->content->value;
		value1 = ((t_vars *)temporary->content)->value;
		temporary = temporary->next;
		if (temporary != NULL)
			//value2 = temporary->content->value;
			value2 = ((t_vars *)temporary->content)->value;
		if (temporary != NULL)
		{
			if (!(value1 < value2))
			{
				sorted++;
			}
		}
	}
	if (sorted == 0)
	{
		freeList(head);
		exit(1);
	}
}

t_list *ft_sorted_handler(char **argv, t_list *list)
{
	t_list *temp;
	t_vars *temp2;
	int	i;
	int j;
	int counter;

	i = 1;
	j = 0;
	counter = 0;
	//list = ft_lstnew(ft_atoi(argv[1]));

	//list = ft_lstnew(ft_atoi(argv[1]));
	//list->index = counter;

	while (argv[i])
	{

		j = ft_atoi(argv[i]);
		temp2 = (t_vars *)ft_calloc(1, sizeof(t_vars));
		temp2->value = j;
		temp2->index = counter;
		//printf("Index is: %d\n ", temp2->index);
		//printf("Index is: %d\n ", temp2->value);
		temp = ft_lstnew(temp2);
		//temp->content = temp2;
		ft_lstadd_back(&list, temp);
		//printf("List is : %p", list->content);
		counter++;
		i++;
	}
	/*while (argv[i])
	{
		counter++;
		j = ft_atoi(argv[i]);
		temp = ft_lstnew(j);
		temp->index = counter;
		ft_lstadd_back(&list, temp);
		i++;
	}*/
	//printlist(list);
	check_if_sorted_list_is_sorted(list);
	//printlist(list);
	//freeList(list);
	//return (list);
	return (list);
}

void freeList(t_list *head)
{
   t_list *tmp;

   while (head != NULL)
    {
		//printf("Address is %p and value is %i \n", head, head->value);
       tmp = head;

       head = head->next;
 	   free(tmp->content);
       free(tmp);
    }
}





//SPYRO BRAINIAC!!!
/*
int    check_if_sorted(int *arr, int length)
{
    int    i;
    int    k;

    i = 0;
    k = 0;
    while (length - 1 > 0)
    {
        if (arr[i] < arr[i + 1])
            i++;
        else
            k++;
        length--;
    }
    if (k == 0)
        return(1);
    else
        return(0);
}*/

/*
void printlist1(t_list *head)
{
	t_list *temporary = head;

	while (temporary != NULL)
	{
		if ((char *)temporary->content)
		{
			//printf("%d - ", temporary->value);
			//printf("VALUE IS %d - \n", temporary->next->value);
		}
		temporary = temporary->next;


	}
	printf("\n");
}*/