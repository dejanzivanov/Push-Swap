#include "../inc/ft_push_swap.h"

void	printlist(t_list *head)
{
	t_list	*temporary;
	int		i;

	temporary = head;
	i = 0;
	while (temporary != NULL)
	{
		//printf("%d -> ", ((t_vars *)temporary->content)->value);
		//ft_put_nbrbase((((t_vars *)temporary->content)->value), "01");
		//write(1, "\n", 1);
		printf(" %d -> ", ((t_vars *)temporary->content)->value);
		//printf("Sorted Index is %d -> ", ((t_vars *)temporary->content)->sorted_index);
		//printf("Sorted Index is %s -> ", ((t_vars *)temporary->content)->bin_num);
		temporary = temporary->next;
		i++;
	}
	printf("NULL");
	printf("\n");
}


void	printlist5(t_list *head)
{
	t_list	*temporary;
	int		i;

	temporary = head;
	i = 0;
	while (temporary != NULL)
	{
		//printf("%d -> ", ((t_vars *)temporary->content)->value);
		//ft_put_nbrbase((((t_vars *)temporary->content)->value), "01");
		//write(1, "\n", 1);
		//printf(" is and the value is %d -> ", ((t_vars *)temporary->content)->value);
		//printf("Sorted Index is %d -> ", ((t_vars *)temporary->content)->sorted_index);
		printf("Sorted Index is %s -> ", ((t_vars *)temporary->content)->bin_num);
		temporary = temporary->next;
		i++;
	}
	printf("NULL");
	printf("\n");
}

/*
**	i[0] - Value1
**	i[1] - Value2
**	i[2] - Sorted
*/

void	check_if_sorted_list_is_sorted(t_list *head)
{
	t_list	*temporary;
	int		values[3];

	temporary = head;
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
	{
		ft_free_list(head);
		exit(1);
	}
}

t_list	*ft_sorted_handler(char **argv, t_list *list)
{
	t_list	*temp;
	t_vars	*temp2;
	int		i;
	int		j;
	int		counter;

	i = 1;
	j = 0;
	counter = 0;
	while (argv[i])
	{
		j = ft_atoi(argv[i]);
		temp2 = (t_vars *)ft_calloc(1, sizeof(t_vars));
		temp2->value = j;
		temp2->index = counter;
		temp = ft_lstnew(temp2);
		ft_lstadd_back(&list, temp);
		counter++;
		i++;
	}
	check_if_sorted_list_is_sorted(list);
	return (list);
}

void	ft_free_list(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
}
