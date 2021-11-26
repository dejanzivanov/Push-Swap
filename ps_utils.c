/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:52:20 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/26 02:23:20 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	just_the_two_of_us(t_list **head)
{
	if ((*head)->value > (*head)->next->value)
	{
		sa(head);
		exit(0);
	}
	else
		exit(0);
}

long int *take_arg(int len, char *argv[])
{
	int	i;
	int	j;
	long int	*arr;
	long int	tmp;

	j = 1;
	i = 0;
	if (len > 2)
	{
		len -= 1;
		check_non_num(argv, len);
	}
	else if (len == 2)
	{
		check_non_num(argv, len - 1);
		exit(-1);
	}
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
	check_duplicate(arr, len);
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
	if (len == 2)
		just_the_two_of_us(&major_a);
	if (len == 3)
		sort_3(&major_a);
	if (len == 5)
		sort_5(major_a, major_b, len);
	else
		sort_more(&major_a, &major_b, len);
		//lazysort(&major_a, &major_b, len);
}

void	sort_3(t_list **head)
{
	t_list *top;

	top = *head;
	if (top->value < top->next->value && top->next->value > top->next->next->value && top->value < top->next->next->value) // 1 3 2
	{
		rra(head);
		sa(head);
	}
	else if (top->value < top->next->value && top->next->value > top->next->next->value && top->value > top->next->next->value)
		rra(head);
	else if (top->value > top->next->value && top->next->value < top->next->next->value && top->next->next->value > top->value) // 2 1 3
		sa(head);
	else if (top->value > top->next->value && top->next->value > top->next->next->value && top->next->next->value < top->value) // 3 2 1
	{
		ra(head);
		sa(head);		
	}
	else if (top->value > top->next->value && top->next->value < top->next->next->value && top->value > top->next->next->value) // 3 1 2
		ra(head);
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

// t_list	*ft_antepenultimate(t_list *head)
// {
// 	t_list	*last;
// 	t_list	*lst;
// 	t_list	*pen;

// 	lst = head;
// 	last = ft_lstlast(lst);
// 	pen = ft_lst_penultimate(lst);
// 	while (lst->next != last && lst->next != pen)
// 		lst = lst->next;
// 	return (lst);
// }

int	find_min(t_list **head)
{
	int	min_val;
	t_list	*lst;

	lst = *head;
	min_val = lst->value;
	while(lst != NULL)
	{
		if (lst->value < min_val)
			min_val = lst->value;
		lst = lst->next;
	}
	return (min_val);
}

void	bring_min_up(int min_v, t_list **head, int len)
{
	int	i;
	t_list	*lst;
	t_list	*major;

	i = 1;
	lst = *head;
	major = *head;
	while (lst->value != min_v)
	{
		i++;
		lst = lst->next;	
	}
	if (min_v == major->value)
		return ;
	if (i >= len / 2)
		call_rra(head, (len - i + 1));
	else if (i == 2)
		ra(head);
	else
		call_ra(head, (len - i - 1));
}

void	call_ra(t_list **head, int counter)
{
	while(counter > 0)
	{
		ra(head);
		counter--;
	}
}

void	call_rra(t_list **head, int counter)
{
	while(counter > 0)
	{
		rra(head);
		counter--;
	}
}

void	sort_5(t_list *major_a, t_list *major_b, int len)
{
	int	min_v;
	
	min_v = find_min(&major_a);
	bring_min_up(min_v, &major_a, len);
	pb(&major_a, &major_b);
	min_v = find_min(&major_a);
	bring_min_up(min_v, &major_a, len - 1);
	pb(&major_a, &major_b);
	printlst(major_b);
	sort_3(&major_a);
	pa(&major_a, &major_b);
	pa(&major_a, &major_b);
	// printf("Is it sorted?\n");
	// printlst(major_a);
}

void	send_half(t_list **major_a, t_list **major_b, int len)
{
	int	limit;
	int counter;
	t_list *last;

	limit = find_min(major_a) + len / 2;
	counter = 0;
	while ((*major_a)->next->next->next != NULL && counter <=limit)
	{
		if (find_min(major_a) > limit)
			return ;
		last = ft_lstlast(*major_a);
		if ((*major_a)->next->value <= limit)
		{
			sa(major_a);
			pb(major_a, major_b);
			last = ft_lstlast(*major_a);
			counter++;
		}
		else if (last->value <= limit)
		{
			rra(major_a);
			pb(major_a, major_b);
			counter++;
		}
		else if ((*major_a)->value <= limit)
		{
			pb(major_a, major_b);
			last = ft_lstlast(*major_a);
			counter++;
		}
		else
			rra(major_a);
	}
	return ;
}

void	sort_more(t_list **major_a, t_list **major_b, int len)
{
	int counter = len;
	while (counter - 3 > 0)
	{
		if (counter - 3 == 1)
		{
			just_the_four_of_us(major_a, major_b);
			break;
		}
		send_half(major_a, major_b, counter);
		counter = (counter / 2 - 1);
	}
		sort_3(major_a);
		len = 3;
		while(*major_b != NULL)
		{
			push_back(major_a, major_b, len);
			len++;
		}
		//bring_min_up(0, major_a, len);
		exit_stage(*major_a);
}

void	exit_stage(t_list *head)
{
	t_list	*previous;
	// t_list	*next;
	t_list	*this;

	previous = head;
	this = head->next;
	while (this != NULL)
	{
		free(previous);
		previous = NULL;
		previous = this;
		this = this->next;
	}
	free(previous);
}

void	just_the_four_of_us(t_list **major_a, t_list **major_b)
{
	int i;

	i = find_min(major_a);
	bring_min_up(i, major_a, 4);
	pb(major_a, major_b);
}

void	push_back(t_list **major_a, t_list **major_b, int len)
{
	t_list	*_next;
	int		steps;

	steps = 0;
	_next = *major_a;
	while((*major_b)->value > _next->value && _next != NULL) //? or <len
	{
		_next = _next->next;
		steps++;		
	}
	if (steps == 0)
		pa(major_a, major_b);
	else if (steps < len / 2)
	{
		call_ra(major_a, steps);
		pa(major_a, major_b);
		call_rra(major_a, steps);
	}
	else if (steps == len)
	{
		pa(major_a, major_b);
		ra(major_a);
	}
	else
	{
		call_rra(major_a, steps);
		pa(major_a, major_b);
		call_ra(major_a, steps + 1);
	}
}

void	lazysort(t_list **major_a, t_list **major_b, int len)
{
	int	min_v;
	
	while ((*major_a)->next != NULL)
	{
		min_v = find_min(major_a);
		bring_min_up(min_v, major_a, len);
		pb(major_a, major_b);
		len --;
	}
}
