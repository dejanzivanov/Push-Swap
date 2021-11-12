#include "../inc/ft_push_swap.h"

void	ft_error_printer()
{

	write(2,"Error\n", 6);
	exit(EXIT_FAILURE);
}

void    ft_duplicate_checker(char **argv)
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

void	ft_range_checker(char **argv)
{
	int	i;
	long	k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		k = ft_atoi(argv[i]);
		if ((k < INT_MIN) || (k > INT_MAX))
			ft_error_printer();
		i++;
	}

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

void	ft_error_handler(char **argv)
{
	ft_non_numeric_handler(argv); 
	ft_range_checker(argv); //CHECKS MIN INT / MAX INT (ft_range_checker(char **argv))
	ft_duplicate_checker(argv); //CHECKS DUPLICATES
}