#include "../inc/ft_push_swap.h"

void    ft_handle_five_hundred(t_list **stack_a, t_list **stack_b)
{
    //printf("Starting to sort 500 arguments\n");


    t_list *temp;
    int nav;
    int    max;
    int    bits;
    int    i;
    int counter;

    counter = 0;
    bits = 0;
    nav = 0;
    i = 0;
    temp = *stack_a;
    max = ((t_vars *)(temp)->content)->value;
    while (temp->next != NULL )
    {
        if (max < ((t_vars *)(temp)->next->content)->value)
            max = ((t_vars *)(temp)->next->content)->value;
        temp = temp->next;
    }
    // max-=1;
    while((max>>bits) != 0)
    {
        bits++;
    }
    bits++;
    while (i < bits)
    {
        counter = ft_lstsize(*stack_a);
        nav = 0;
        while (nav < counter)
        {
            if((((t_vars *)(*stack_a)->content)->sorted_index)>>i&1 == 1)
                {
                    rotate_stack(stack_a, "ra");
                }
            else
                {
                    push_b(stack_a, stack_b);
                }
            nav += 1;
        }
        nav = 0;
        counter = ft_lstsize(*stack_b);
        while (nav < counter)
        {
            push_a(stack_a, stack_b);
             nav += 1;
        }
		if(ft_is_sorted(stack_a) == 1)
			break ;
        i++;
    }
}