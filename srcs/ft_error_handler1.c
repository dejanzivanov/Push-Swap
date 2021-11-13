#include "../inc/ft_push_swap.h"

void	ft_error_printer()
{
	write(2,"Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_non_numeric_handler(char **argv)
{
	int i;
	int j;
	long k;

	i = 1;
	j = 0;
	k = 0;
	while (argv[i])
	{
		if((ft_strlen(argv[i]) == 1) && (argv[i][0] == '0'))
			k = ft_atoi((argv[i]));
		else
			k = ft_atoi_special((argv[i]));
		if (k == 2147483649 || k > INT_MAX )
			ft_error_printer();
		i++;
	}
}

void	ft_int_range_handler(char **argv)
{
	int i;
	long j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = ft_atoi(argv[i]);
		if (j < INT_MIN || j > INT_MAX)
			ft_error_printer();
		i++;
	}
}

void	ft_duplicate_handler(char **argv)
{
	int i;
	int j;
	int k;
	int l;

	i = 1;
	k = 2;
	l = 0;
	while (argv[i])
	{
		j = ft_atoi(argv[i]);

		while (argv[k])
		{
			l = ft_atoi(argv[k]);
			if (j == l)
				ft_error_printer();
			k++;
		}
		i++;
		k = i + 1;
	}
}

void	ft_error_handler(char **argv)
{
	ft_non_numeric_handler(argv);
	ft_int_range_handler(argv);
	ft_duplicate_handler(argv);
	ft_sorted_handler(argv);
}

/*
** +2147483647 - INT_MAX
** -2147483648 - INT_MIN
*/

/*
1. The string is traversed character by character.
2. Each character is checked for duplicates.
3. If a character is duplicate, it is printed.
4. If a character is not duplicate, it is set to 0.
*/