/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:08:28 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/23 00:18:39 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*rra(t_list *head)
{
	t_list	*sherpa;
	t_list	*pen;

	sherpa = ft_lstlast(head);
	pen = ft_lst_penultimate(head);
	sherpa->next = head;
	pen->next = NULL;
	head = sherpa;
	write(1, "rra\n", 4);
	return (head);
}

t_list	*rrb(t_list *head_b)
{
	t_list	*sherpa;
	t_list	*pen;

	sherpa = ft_lstlast(head_b);
	pen = ft_lst_penultimate(head_b);
	sherpa->next = head_b;
	pen->next = NULL;
	head_b = sherpa;
	write(1, "rrb\n", 4);
	return (head_b);
}

void	sa(t_list *head) //swap the two top
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = head;
	second = head->next;
	third = head->next->next;
	head = second;
	second->next = first;
	first->next = third;
	write(1, "sa\n", 3);
}

void	sb(t_list *head_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = head_b;
	second = head_b->next;
	third = head_b->next->next;
	head_b = second;
	second->next = first;
	first->next = third;
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
	if (major_b == NULL)
		return ;
	t_list	*first_a;
	t_list	*first_b;
	//t_list	*second;

	first_b = major_b;
	first_a = major_a;
	major_b = major_b->next;
	first_b->next = first_a;
	major_a = first_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **major_a, t_list **major_b)
{ //kane kai tin pa etsi
	t_list	*top_a;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	top_a = *major_a;
	new->value = top_a->value;
	new->next = *major_b;
	*major_b = new;
	*major_a = top_a->next;
	free(top_a);
	top_a = NULL;
	write(1, "pb\n", 3);
	//return (major_b);
}

t_list	*ra(t_list *head) //first becomes last.
{
	t_list	*first;
	t_list	*sherpa;

	first = head;
	sherpa = ft_lstlast(head);
	head = head->next;
	sherpa->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
	return(head);
}
t_list	*rb(t_list *head_b)
{
	t_list	*first;
	t_list	*sherpa;

	first = head_b;
	sherpa = ft_lstlast(head_b);
	head_b = head_b->next;
	sherpa->next = first;
	first->next = NULL;
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