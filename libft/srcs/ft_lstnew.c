/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a new element. The variable
	’content’ is initialized with the value of the parameter ’content’.
	The variable ’next’ is initialized to NULL.
RETURN VALUE
	The new element.
*/

#include "libft.h"
#include "../../inc/ft_push_swap.h"
/*
t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->value = content;
	elem->next = NULL;
	return (elem);
}*/

t_list    *ft_lstnew(void *content)
{
    t_list    *elem;

    elem = malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    elem->content = content;
	elem->next = NULL;
    return (elem);
}
