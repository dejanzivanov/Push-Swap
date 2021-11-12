#include "pushswap.h"

int *take_arg(int len, char *arg[])
{
	int	i;
	int	j;
	int	*arr;
	int	tmp;

	j = 1;
	i = 0;
	arr = (int *)malloc((len) * sizeof(int));
	if (!arr)
		return (0);
	while (i < len)
	{
		tmp = ft_atoi(arg[j]);
		if (!tmp)
		{
			free (arr);
			write(1,"Error\n", 6);
			exit(-1);
		}
		arr[i] = tmp;
		j++;
		i++;
	}
	check_input(arr, len);
	if (check_if_sorted(arr, len) == 1)
	{
		free (arr);
		return(NULL);
	}
	return (arr);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	check_input(int *arr, int len)
{
	int		i;

	i = 0;
	if (check_duplicate(arr) == -1)
	{
		free(arr);
		return;
	}
	while (len > 0)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			free (arr);
			write(1, "Error\n", 6);
		}
		len --;
		i++;
	}
}

int	check_if_sorted(int *arr, int length)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (length - 1 > 0)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			k++;
		length--;
	}
	if (k == 0)
		return(1);
	else
		return(0);
}

int	*bbsort(int *arr, int len)
{
	int	step;
	int	i;
	int	temp;
	int	flag;
	int	s;

	step = 0;
	i = 0;
	s = 0;
	while (step < len - 1)
	{
		flag = 0;
		i = 0;
		while (i < len - step - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		step++;
	}
	return (arr);
}

int		*copy(int *arr, int len)
{
	int	*storage;
	int	i;

	i = 0;
	storage = (int *)malloc((len) * sizeof(int));
	if (!storage)
		exit(-1);
	while(i < len)
	{
		storage[i] = arr[i];
		i++;
	}
	return (storage);
}

int		check_duplicate(int *arr)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while(arr[i] != '\0')
	{
		j = i + 1;
		while (arr[j] != '\0')
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int *get_sorted_indexes(int *before, int *after, int len)
{
    int    *indexes;
    int    i;
    int    j;
    int    k;

	indexes = (int *)malloc((len + 1)* sizeof(int));
	i = 0;
	j = 0;
	k = 0;
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (before[i] == after[j])
				indexes[k] = j;
			j++;
		}
		i++;
		k++;
	}
	// free (before);
	// free (after);
	return (indexes);
}
