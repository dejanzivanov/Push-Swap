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

	i = 1;
	j = 0;
	while (argv[i])
	{

		while (argv[i][j])
		{
			if (!ft_isdigit((argv[i][j])))
				ft_error_printer();
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_error_handler(char **argv)
{
	ft_non_numeric_handler(argv);

}