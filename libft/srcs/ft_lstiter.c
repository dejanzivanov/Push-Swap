/*
DESCRIPTION
	Iterates the list ’lst’ and applies the function ’f’ to the content
	of each element.
RETURN VALUE
	None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
