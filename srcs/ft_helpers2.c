/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 03:20:25 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 03:20:27 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	ft_close_program(t_list *stack_a)
{
	ft_free_list(stack_a);
	exit(1);
}

void	ft_binary_assignment(int i, t_list **stack_a, int *values)
{
	int		j;
	t_list	*counter;

	j = 0;
	counter = *stack_a;
	while (j < i)
	{
		counter = *stack_a;
		while (counter)
		{
			if (values[j] == ((t_vars *)(*counter).content)->value)
				((t_vars *)(*counter).content)->sorted_index = j;
			counter = (*counter).next;
		}
		j++;
	}
}
