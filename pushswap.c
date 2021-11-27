/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:56:01 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/27 19:30:23 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char *argv[])
{
	long int 	*input;
	long int	*sorted;
	long int	*unsorted;
	long int	*indexed;
	t_list		*stack_a;

	if (argc == 1)
		return (0);
	input = take_arg(argc, argv);
	unsorted = copy(input, argc - 1);
	sorted = bbsort(input, argc - 1);
	indexed = get_sorted_indexes(unsorted, sorted, argc - 1);
	free(unsorted);
	free(sorted);
	stack_a = init_struct(indexed, argc - 1);
	//printlst(stack_a);
	exit_stage(stack_a);
	return (0);
}
