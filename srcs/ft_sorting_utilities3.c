//VLAD IS FUCKIN HATING THE LISTS
#include "../inc/ft_push_swap.h"

void ft_index_update(t_list **stack)
{
	t_list *temporary = *stack;
	int i = 0;

	while (temporary != NULL)
	{
		//printf("INDEX IS : %d \n", *(temporary)->content->value);
		//printf("INDEX IS : %d \n", *(*(temporary->content))->index);
		//printf("VALUE IS : %d \n", (*(t_list *)temporary)->(t_vars *)content->value);
		((t_vars *)temporary->content)->index = i;
		i++;
		//printf("idfag %d\n", head->(t_vars *)content->value);
		//printf("idfag %d\n", ((t_list *)head)->content.value);
		//printf("idfag %d\n", ((t_list *)head)->content->value);
		//printf("idfag %d\n", ((t_list *)head)->((t_vars *)content)->value);
		temporary = temporary->next;
		//printf("I is: %d\n", i);
	}
}