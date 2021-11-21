#include "../inc/ft_push_swap.h"

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
	//t_list	*temp;
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
		//temp = ft_lstnew(temp2);
		//ft_lstadd_back(&list, temp);
		ft_lstadd_back(&list, ft_lstnew(temp2));

		counter++;
		i++;
	}
	//ft_free_list(temp);
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
