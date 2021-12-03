/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:07:45 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 03:16:54 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_argument_check(t_list **stack_a, t_list **stack_b)
{
	int	argument_num;

	argument_num = ft_lstsize(*stack_a);
	if (argument_num == 2)
	{
		ft_handle_two(stack_a);
	}
	else if (argument_num == 3)
	{
		ft_handle_three(stack_a);
	}
	else if (argument_num == 4)
	{
		ft_handle_four(stack_a, stack_b);
	}
	else if (argument_num == 5)
	{
		ft_handle_five(stack_a, stack_b);
	}
	else if (argument_num > 5)
	{
		ft_handle_hundred(stack_a, stack_b);
	}
}

void	ft_sorting_helper(t_list **s_a, t_list **s_b, int i)
{
	int	nav;
	int	counter;

	counter = ft_lstsize(*s_a);
	nav = 0;
	while (nav < counter)
	{
		if (((((t_vars *)(*s_a)->content)->sorted_index) >> i & 1) == 1)
			rotate_stack(s_a, "ra");
		else
			push_b(s_a, s_b);
		nav += 1;
	}
}

int	ft_get_bits(t_list **stack_a)
{
	t_list	*temp;
	int		max;
	int		bits;

	bits = 0;
	temp = *stack_a;
	max = ((t_vars *)(temp)->content)->sorted_index;
	while (temp->next != NULL )
	{
		if (max < ((t_vars *)(temp)->next->content)->sorted_index)
			max = ((t_vars *)(temp)->next->content)->sorted_index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	bits++;
	return (bits);
}

/*
**	i[0] = nav
**	i[1] = i
*/

void	ft_handle_hundred(t_list **stack_a, t_list **stack_b)
{
	int		i[4];
	int		bits;
	int		counter;

	i[0] = 0;
	i[1] = 0;
	counter = 0;
	bits = ft_get_bits(stack_a);
	while (i[1] < bits)
	{
		ft_sorting_helper(stack_a, stack_b, i[1]);
		i[0] = 0;
		counter = ft_lstsize(*stack_b);
		while (i[0] < counter)
		{
			push_a(stack_a, stack_b);
			i[0] += 1;
		}
		if (ft_is_sorted(stack_a) == 1)
		{
			ft_free_list(*stack_a);
			return ;
		}
		i[1]++;
	}
}
