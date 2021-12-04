/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:20:44 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 03:20:47 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	rrr_helper(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;

	second_last = NULL;
	last = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	else
	{
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	swap_helper(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp3 = (*stack)->next->next;
	tmp2 = (*stack)->next;
	tmp1 = *stack;
	*stack = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
}

/*
**	FIRST ELEM BECOMES LAST
*/

void	rr_helper(t_list **stack)
{
	t_list	*elem1;
	t_list	*elem2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	elem1 = (*stack)->next;
	elem2 = *stack;
	ft_lstadd_back(stack, *stack);
	elem2->next = NULL;
	*stack = elem1;
}

void	ft_reverse_rotate_helper(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack(stack_a, "rra");
	reverse_rotate_stack(stack_a, "rra");
	push_b(stack_a, stack_b);
}
