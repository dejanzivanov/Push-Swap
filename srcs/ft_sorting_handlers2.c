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
