/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:52:20 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/23 00:16:52 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	just_the_two_of_us(long int *input)
{
	int	holder;
	if (input[1] > input[2])
	{
		holder = input[1];
		input[1] = input[2];
		input[2] = holder;
		write(1, "sa\n", 3);
		exit(0);
	}
	else
		exit(0);
}

long int *take_arg(int len, char *argv[]) //raw check here, return int* 
{
	int	i;
	int	j;
	long int	*arr;
	long int	tmp;

	j = 1;
	i = 0;
	check_non_num(argv, len);
	arr = (long int *)malloc((len) * sizeof(long int));
	if (!arr)
		return (0);
	while (i < len)
	{
		tmp = ft_atoi(argv[j]);
		arr[i] = tmp;
		j++;
		i++;
	}
	check_range(arr, len);
	check_duplicate(arr);
	check_if_sorted(arr, len);
	return (arr);
}

long int	ft_atoi(const char *str)
{
	long int	sign;
	long int	result;

	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}


long int	*bbsort(long int *arr, int len)
{
	int	step;
	int	i;
	int	temp;
	int	flag;
	int	s;

	step = 0;
	i = 0;
	s = 0;
	while (step < len - 1)
	{
		flag = 0;
		i = 0;
		while (i < len - step - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		step++;
	}
	return (arr);
}

long int		*copy(long int *arr, int len)
{
	long int	*storage;
	int	i;

	i = 0;
	storage = (long int *)malloc((len) * sizeof(long int));
	if (!storage)
		exit(-1);
	while(i < len)
	{
		storage[i] = arr[i];
		i++;
	}
	return (storage);
}


long int *get_sorted_indexes(long int *before, long int *after, int len)
{
    long int    *indexes;
    int    i;
    int    j;
    int    k;

	indexes = (long int *)malloc((len + 1)* sizeof(long int));
	i = 0;
	j = 0;
	k = 0;
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (before[i] == after[j])
				indexes[k] = j;
			j++;
		}
		i++;
		k++;
	}
	return (indexes);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*holder;

	if (lst)
	{
		holder = ft_lstlast((lst));
		holder->next = new;
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*instance;

	instance = (t_list *)malloc(sizeof(t_list));
	if (!instance)
		return (NULL);
	instance->value = value;
	instance->next = NULL;
	return (instance);
}

void	printlst(t_list *lst)
{
	while (lst)
	{
		printf("%d :  %p\n", lst->value, lst);
		lst = lst->next;
	}
}

int		init_struct(long int *indexed, int len)
{
	t_list	*major_a;
	t_list	*major_b;
	t_list	*new;
	int		i;

	i = 0;
	major_b = NULL;
	new = ft_lstnew(indexed[i]);
	major_a = new;
	i++;
	while (i < len)
	{
		new = ft_lstnew(indexed[i]);
		ft_lstadd_back(major_a, new);
		i++;
	}
	sort_stack(major_a, major_b, len);

	return (0);
}

void	sort_stack(t_list *major_a, t_list *major_b, int len)
{
	if (len == 3)
		sort_3(major_a);
	if (len == 5)
		sort_5(major_a, major_b, len);
}

void	sort_3(t_list *head)
{
	if (head->value < head->next->value && head->next->value > head->next->next->value && head->value < head->next->next->value) // 1 3 2 
	{
		sa(head);
		printlst(head);
	}
	else if (head->value < head->next->value && head->next->value > head->next->next->value && head->value > head->next->next->value)
	{
		head = rra(head);
	}
	else if (head->value > head->next->value && head->next->value < head->next->next->value && head->next->next->value > head->value) // 2 1 3
	{
		sa(head);
		head = rra(head);
	}
	else if (head->value > head->next->value && head->next->value > head->next->next->value && head->next->next->value < head->value) // 3 2 1
	{
		printf("Case: 3 2 1\n");
		head = rra(head);
		sa(head);
		
	}
	else if (head->value > head->next->value && head->next->value < head->next->next->value && head->value > head->next->next->value) // 3 1 2
		head = ra(head);
	//printlst(head);
}

t_list	*ft_lst_penultimate(t_list *head)
{
	t_list	*last;
	t_list	*lst;

	lst = head;
	if (!lst)
		return (NULL);
	last = ft_lstlast(head);
	while (lst->next != last)
		lst = lst->next;
	return (lst);
}

t_list	*ft_antepenultimate(t_list *head)
{
	t_list	*last;
	t_list	*lst;
	t_list	*pen;

	lst = head;
	last = ft_lstlast(lst);
	pen = ft_lst_penultimate(lst);
	while (lst->next != last && lst->next != pen)
		lst = lst->next;
	return (lst);
}

t_list	*find_min(t_list *head)
{
	int	min_val;
	t_list	*lst;
	t_list	*send;

	min_val = head->value;
	lst = head;
	while(lst->next != NULL)
	{
		if (lst->value < min_val)
		{
			min_val = lst->value;
			send = lst;
		}
		lst = lst->next;
	}
	return (send);
}

t_list	*bring_min_up(t_list *min_s, t_list *head, int len)
{
	int	i;
	t_list	*lst;

	i = 1;
	lst = head;
	while (lst->value != min_s->value)
	{
		i++;
		lst = lst->next;	
	}
	printf("Len: %d, i: %d\n", len, i);
	if (i >= len / 2)
		head = call_rra(head, (len - i + 1));
	else
		head = call_ra(head, i);
	//printlst(head);
	return (head);
}

t_list	*call_ra(t_list *head, int counter)
{
	while(counter > 0)
	{
		head = ra(head);
		counter--;
	}
	return(head);
}

t_list	*call_rra(t_list *head, int counter)
{
	while(counter > 0)
	{
		head = rra(head);
		counter--;
	}
	return(head);
}

void	sort_5(t_list *major_a, t_list *major_b, int len)
{
	t_list	*min_s;
	
	min_s = find_min(major_a);
	major_a = bring_min_up(min_s, major_a, len);
	//major_a = pb(&major_a, &major_b);
	pb(&major_a, &major_b);
	printf("Line 355:\n");
	printf("Stack_a:\n");
	printlst(major_a);
	printf("Stack_b:\n");
	printlst(major_b);
	// min_s = find_min(major_a);
	// major_a = bring_min_up(min_s, major_a, len - 2);
	// major_b = pb(major_a, major_b);
	// sort_3(major_a);
	// pa(major_a, major_b);
	// pa(major_a, major_b);
	// printlst(major_a);
}
