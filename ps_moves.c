/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:08:28 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/29 00:08:10 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_list **head) //last becomes first
{
	t_list	*sherpa;
	t_list	*pen;
	t_list	*new;
	t_list	*top;

	top = *head;
	sherpa = ft_lstlast(top);
	pen = ft_lst_penultimate(*head);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = sherpa->value;
	new->next = top;
	*head = new;
	pen->next = NULL;
	free(sherpa);
	sherpa = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **head_b)
{
	t_list	*sherpa;
	t_list	*pen;
	t_list	*new;
	t_list	*top;

	top = *head_b;
	sherpa = ft_lstlast(top);
	pen = ft_lst_penultimate(*head_b);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = sherpa->value;
	new->next = top;
	*head_b = new;
	pen->next = NULL;
	free (sherpa);
	write(1, "rrb\n", 4);
}

void	sa(t_list **head) //swap the two top
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *head;
	second = (*head)->next;
	third = (*head)->next->next;
	*head = second;
	second->next = first;
	first->next = third;
	write(1, "sa\n", 3);
}

void	sb(t_list **head_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *head_b;
	second = (*head_b)->next;
	third = (*head_b)->next->next;
	*head_b = second;
	second->next = first;
	first->next = third;
	write(1, "sb\n", 3);
}
void	ss(t_list **major_a, t_list **major_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *major_b;
	second = (*major_b)->next;
	third = (*major_b)->next->next;
	*major_b = second;
	second->next = first;
	first->next = third;
	first = *major_a;
	second = (*major_a)->next;
	third = (*major_a)->next->next;
	*major_a = second;
	second->next = first;
	first->next = third;
	write(1, "ss\n", 3);
}
void	pa(t_list **major_a, t_list **major_b)
{
	t_list	*top_b;
	t_list	*new;

	top_b = *major_b;
	if (top_b == NULL)
		return ;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = (*major_b)->value;
	if (*major_a == NULL)
		new->next = NULL;
	else
		new->next = *major_a;
	*major_a = new;
	*major_b = top_b->next;
	free(top_b);
	top_b = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_list **major_a, t_list **major_b)
{
	t_list	*top_a;
	t_list	*new;

	top_a = *major_a;
	if (top_a == NULL)
		return ;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = (*major_a)->value;
	if (*major_b == NULL)
		new->next = NULL;
	else
		new->next = *major_b;
	*major_b = new;
	*major_a = top_a->next;
	free(top_a);
	top_a = NULL;
	write(1, "pb\n", 3);
}

void	ra(t_list **head) //first becomes last.
{
	t_list	*first;
	t_list	*sherpa;
	t_list	*new;

	first = *head;
	sherpa = ft_lstlast(*head);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = first->value;
	new->next = NULL;
	*head = first->next;
	sherpa->next = new;
	free(first);
	first = NULL;
	write(1, "ra\n", 3);
}
void	rb(t_list **head_b)
{
	t_list	*first;
	t_list	*sherpa;
	t_list	*new;

	first = *head_b;
	sherpa = ft_lstlast(*head_b);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = first->value;
	new->next = NULL;
	sherpa = ft_lstlast(*head_b);
	*head_b = first->next;
	sherpa->next = new;
	free(first);
	first = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **major_a, t_list **major_b)
{
	t_list	*first;
	t_list	*sherpa;
	t_list	*new_a;
	t_list	*new_b;

	first = *major_a;
	sherpa = ft_lstlast(*major_a);
	new_a = (t_list *)malloc(sizeof(t_list));
	if (!new_a)
		return ;
	new_a->value = first->value;
	new_a->next = NULL;
	*major_a = first->next;
	sherpa->next = new_a;
	free(first);
	first = NULL;
	first = *major_b;
	sherpa = ft_lstlast(*major_b);
	new_b = (t_list *)malloc(sizeof(t_list));
	if (!new_b)
		return ;
	new_b->value = first->value;
	new_b->next = NULL;
	sherpa = ft_lstlast(*major_b);
	*major_b = first->next;
	sherpa->next = new_b;
	free(first);
	first = NULL;
	write(1, "rr\n", 3);
}

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

void	rrr(t_list **major_a, t_list **major_b)
{
	t_list	*sherpa;
	t_list	*pen;
	t_list	*new_a;
	t_list	*new_b;
	t_list	*top;

	top = *major_a;
	sherpa = ft_lstlast(top);
	pen = ft_lst_penultimate(*major_a);
	new_a = (t_list *)malloc(sizeof(t_list));
	if (!new_a)
		return ;
	new_a->value = sherpa->value;
	new_a->next = top;
	*major_a = new_a;
	pen->next = NULL;
	free(sherpa);
	sherpa = NULL;

	top = *major_b;
	sherpa = ft_lstlast(top);
	pen = ft_lst_penultimate(*major_b);
	new_b = (t_list *)malloc(sizeof(t_list));
	if (!new_b)
		return ;
	new_b->value = sherpa->value;
	new_b->next = top;
	*major_b = new_b;
	pen->next = NULL;
	free (sherpa);
	write(1, "rrr\n", 4);
}

int	check_weird_sending(t_list **major_a, t_list **major_b, int counter, int limit)
{
	t_list	*last_a;
	t_list	*last_b;
	int counter_start;

	counter_start = counter;
	if (counter <= limit && (*major_a)-> value <= limit && (*major_a)->next && (*major_b)->next)
	{
		if ((*major_a)-> value <= limit && \
		(*major_a)->value > (*major_a)->next->value && \
		(*major_b)->value < (*major_b)->next->value && \
		(*major_a)->next->value > (*major_b)->next->value)
		{
			ss(major_a, major_b);
			pb(major_a, major_b);
			counter++;
			if ((*major_a)-> value <= limit)
			{
				pb(major_a, major_b);
				counter++;
			}
		}
		last_a = ft_lstlast(*major_a);
		last_b = ft_lstlast(*major_b);
		if (last_a->value <= limit && \
		last_a->value < (*major_a)->value && \
		last_b->value > (*major_b)->value && \
		last_a->value > last_b->value)
		{
			rrr(major_a, major_b);
			pb(major_a, major_b);
			counter++;
		}
		if ((*major_a)->value <= limit && (*major_a)->next->value <= limit && \
		(*major_a)->next->value < (*major_a)->value && \
		(*major_a)->next->value > (*major_b)->next->value)
		{
				rr(major_a, major_b);
				pb(major_a, major_b);
				rra(major_a);
				pb(major_a, major_b);
				rrb(major_b);
				counter += 2;
		}
	}
	if (counter == counter_start)
		return (0);
	else
		return (counter);
}