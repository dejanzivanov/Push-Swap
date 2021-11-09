/*
DESCRIPTION
	Counts the number of elements in a list.
RETURN VALUE
	Length of the list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
