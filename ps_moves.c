/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:08:28 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/22 19:09:34 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*rra(t_list *head)
{
	t_list	*last;
	t_list	*pen;

	last = ft_lstlast(head);
	pen = ft_lst_penultimate(head);
	pen->next = NULL;
	last->next = head;
	head = last;
	write(1, "rra\n", 4);
	return (head);
}

t_list	*rrb(t_list *head_b)
{
	t_list	*last;
	t_list	*pen;

	last = ft_lstlast(head_b);
	pen = ft_lst_penultimate(head_b);
	pen->next = NULL;
	last->next = head_b;
	head_b = last;
	write(1, "rrb\n", 4);
	return (head_b);
}

void	sa(t_list *head) //swap the two top
{
	t_list	*last;
	t_list	*pen;
	t_list	*ante;

	last = ft_lstlast(head);
	pen = ft_lst_penultimate(head);
	ante = ft_antepenultimate(head);
	printf("last %d, pen %d, ante %d\n", last->value, pen->value, ante->value);
	ante->next = last;
	last->next = pen;
	pen->next = NULL;
	write(1, "sa\n", 3);
}

void	sb(t_list *head_b)
{
	t_list	*last;
	t_list	*pen;
	t_list	*ante;

	last = ft_lstlast(head_b);
	pen = ft_lst_penultimate(head_b);
	ante = ft_antepenultimate(head_b);
	last->next = pen;
	pen->next = NULL;
	ante->next = last;
	write(1, "sb\n", 3);
}
void	ss(t_list *major_a, t_list *major_b)
{
	sa(major_a);
	sb(major_b);
	write(1, "ss\n", 3);
}
void	pa(t_list *major_a, t_list *major_b)
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	*pen_a;

	top_a = ft_lstlast(major_a);
	top_b = ft_lstlast(major_b);
	pen_a = ft_lst_penultimate(major_a);
	top_b->next = top_a;
	pen_a->next = NULL;
	write(1, "pa\n", 3);
}

t_list	*pb(t_list *major_a, t_list *major_b)
{
	t_list	*top_a;
	t_list	*pen_a;
	t_list	*new;
	

	pen_a = ft_lst_penultimate(major_a);
	top_a = ft_lstlast(major_a);
	if (major_b == NULL)
	{
		new = (t_list*)malloc(sizeof(t_list));
		if (!new)
			exit(-1);
		new->value = top_a->value;
		new->next = NULL;
		major_b = new;
		free(top_a);
		pen_a->next = NULL;
	}
	else
	{
		new = (t_list*)malloc(sizeof(t_list));
		if (!new)
			exit(-1);
		new->value = top_a->value;
		new->next = NULL;
		ft_lstadd_back(major_b, new);
		free(top_a);
		pen_a->next = NULL;
	}
	// printlst(major_b);
	write(1, "pb\n", 3);
	return (major_b);
}

t_list	*ra(t_list *head) //first becomes last.
{
	t_list	*last;
	t_list	*sherpa;

	last = ft_lstlast(head);
	sherpa = head;
	last->next = head;
	head = head->next;
	sherpa->next = NULL;
	write(1, "ra\n", 3);
	printf("After ra, head value= %d\n", head->value);
	last = ft_lstlast(head);
	printf("After ra, last value= %d\n", last->value);
	return(head);
}
t_list	*rb(t_list *head_b)
{
	t_list	*last;
	t_list	*pen;

	last = ft_lstlast(head_b);
	pen = ft_lst_penultimate(head_b);
	last->next = head_b;
	pen->next = NULL;
	head_b = last;
	write(1, "rb\n", 3);
	return(head_b);
}

// void	rr(t_list *major_a, t_list *major_b)
// {
// 	major_a = ra(major_a);
// 	major_b = rb(major_b);
// 	write(1, "rr\n", 3);
// }

size_t	ft_strlen(const char *s)
{
	size_t	counter;
	char	*p;

	counter = 0;
	p = (char *)s;
	while (*p != '\0')
	{
		counter++;
		p++;
	}
	return (counter);
}