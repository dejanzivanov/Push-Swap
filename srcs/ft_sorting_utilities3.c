#include "../inc/ft_push_swap.h"

void	ft_index_update(t_list **stack)
{
	t_list	*temporary;
	int		i;

	temporary = *stack;
	i = 0;
	while (temporary != NULL)
	{
		((t_vars *)temporary->content)->index = i;
		i++;
		temporary = temporary->next;
	}
}

/*
**	Correct way accessing value with typecasting
**	(*(t_list *)temporary)->(t_vars *)content->value)
*/
