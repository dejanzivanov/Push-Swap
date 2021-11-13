#include "../inc/ft_push_swap.h"

void printlist(t_list *head)
{
	t_list *temporary = head;

	while (temporary != NULL)
	{
		printf("J %d \n", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");


}




void	ft_sorted_handler(char **argv)
{
	t_list *head;

	t_list *temp;
	int	i;
	int j;

	i = 1;
	j = 0;

	head = ft_lstnew(-1);
	while (argv[i])
	{
		j = ft_atoi(argv[i]);
		temp = ft_lstnew(j);
		ft_lstadd_back(&head, temp);
		i++;
	}
	printlist(head);
	head->next->value;
	/*while (argv[i])
	{
		j = ft_atoi(argv[i]);
		printf("\nJ IS: %d\n", j);
		/*temp = ft_lstnew(i);
		temp->value = j;
		temp->next = head;
		head = temp;
		printf("%d", j);
		i++;*/
		//temp = ft_lstnew(&temp);
		//temp->value = j;
		//temp->next = head;
		//head = temp;
		//i++;
	//}
	/*while (argv[i])
	{
		//j = ft_atoi(argv[i]);







		//i++;
	}*/

	//printlist1(head);
	//printf("\n");
	//printlist(head);
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
}