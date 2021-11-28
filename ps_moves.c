/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:08:28 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/28 00:54:22 by espyromi         ###   ########.fr       */
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
void	ss(t_list *major_a, t_list *major_b)
{
	sa(&major_a);
	sb(&major_b);
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
	ra(major_a);
	rb(major_b);
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