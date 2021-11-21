#include "../inc/ft_push_swap.h"

void	ft_reverse(char *x, int begin, int end)
{
	char	c;

	if (begin >= end)
		return ;
	c = *(x + begin);
	*(x + begin) = *(x + end);
	*(x + end) = c;
	ft_reverse(x, ++begin, --end);
}

int	ft_check_base(char *base, int base_len, int i, int index)
{
	int	ret_val;

	ret_val = 1;
	if (base_len < 2)
		return (0);
	while (i + index < base_len)
	{
		if (base[i] == base[i + index] || base[i] == '+' || base[i] == '-'
			|| base[i + 1] == '+' || base[i + 1] == '-')
			return (0);
		else
			ret_val = ret_val * ft_check_base(base, base_len, i, index + 1);
		i++;
	}
	return (ret_val);
}

int	ft_print_base(int nbr, char *base, int base_len)
{
	int	counter;

	counter = 1;
	if (nbr / base_len)
		counter = counter + ft_print_base(nbr / base_len, base, base_len);
	return (counter);
}

void	ft_print_base2(int nbr, char *base, char *str, int i)
{
	int	counter;
	int	base_len;

	base_len = ft_strlen(base);
	counter = 1;
	if (nbr / base_len > 0)
		ft_print_base2(nbr / base_len, base, str, i + 1);
	str[i] = *ft_itoa(nbr % base_len);
}

char	*ft_put_nbrbase(int nbr, char *base)
{
	int		base_len;
	char	*str;
	int		value;

	base_len = ft_strlen(base);
	if (ft_check_base(base, base_len, 0, 1))
		value = ft_print_base(nbr, base, base_len);
	str = ft_calloc(sizeof(value) + 1, 1);
	ft_print_base2(nbr, base, str, 0);
	ft_reverse(str, 0, ft_strlen(str) - 1);
	return (str);
}
