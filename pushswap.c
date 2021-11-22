/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:56:01 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/23 00:05:11 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char *argv[])
{
	long int 	*input;
	long int	*sorted;
	long int	*unsorted;
	long int	*indexed;
	//int k = 0;

	if (argc == 2)
		exit (-1);
	input = take_arg(argc - 1, argv);
	unsorted = copy(input, argc - 1);
	sorted = bbsort(input, argc - 1);
	indexed = get_sorted_indexes(unsorted, sorted, argc - 1);
	if (argc == 3)
		just_the_two_of_us(indexed);
	init_struct(indexed, argc - 1);
	return (0);
}
