/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:56:01 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/25 10:22:50 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char *argv[])
{
	long int 	*input;
	long int	*sorted;
	long int	*unsorted;
	long int	*indexed;

	if (argc == 2)
		exit (-1);
	input = take_arg(argc - 1, argv);
	unsorted = copy(input, argc - 1);
	sorted = bbsort(input, argc - 1);
	indexed = get_sorted_indexes(unsorted, sorted, argc - 1);
	free(unsorted);
	free(sorted);
	init_struct(indexed, argc - 1);
	return (0);
}
