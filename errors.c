/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:18:15 by espyromi          #+#    #+#             */
/*   Updated: 2021/11/23 23:51:20 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_non_num(char *argv[], int len)
{
	int			i;
	size_t		j;

	i = 1;
	j = 0;
	while (i <= len)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				write(2, "Error\n", 6);
				exit (-1);
			}
			j++;
		}
		i++;
	}
}

void	check_range(long int *arr, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			panic(arr);
		}
		len--;
		i++;
	}
}

void	check_duplicate(long int *arr, int len)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while(i < len)
	{
		while (j < len)
		{
			if (arr[i] == arr[j])
				panic(arr);
			j++;
		}
		i++;
	}
}

void	check_if_sorted(long int *arr, int length)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	int len = length;
	while (length > 0)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			k++;
		length--;
	}
	if (i == len - 1)
	{
		printf("Already Sorted...\n");
		panic(arr);
	}
}

void	panic(long int *arr)
{
	free (arr);
	write(2, "Error\n", 6);
	exit (-1);
}