#include "../libft/incl/libft.h"
#include <limits.h>
#include <stdio.h> //REMOVE THIS

typedef struct s_vars
{
	unsigned int index;
	int		value;
}			t_vars;

void	ft_handle_two(void);
void	ft_handle_three(void);
void	ft_handle_four(void);
void	ft_handle_five(void);
void	ft_handle_hundred(void);
void	ft_handle_five_hundred(void);
void 	printlist(t_list *head);
void	ft_argument_check(char **argv, t_list *list);
void	freeList(t_list *head);
t_list	*ft_sorted_handler(char **argv, t_list *list);
void	ft_error_printer(t_list *list);

t_list	*ft_error_handler(char **argv, t_list *list);
void	ft_int_range_handler(char **argv, t_list *list);
void	ft_duplicate_handler(char **argv, t_list *list);


void	reverse_rotate_stack(t_list **stack, char *operation); //This is RRA/RRB
void	rrr_helper(t_list **stack);
void	reverse_rotate_a_b(t_list **stack_a,t_list **stack_b); //This is RRR
void	swap(t_list **stack, char* operation); //This is SA/SB
void	swap_a_b(t_list **stack_a, t_list **stack_b); // THIS IS SS
void	swap_helper(t_list **stack);
void	rotate_stack(t_list **stack, char *operation);//THIS IS RA/RB;
void	rr_helper(t_list **stack);
void	rotate_a_b(t_list **stack_a,t_list **stack_b);//THIS IS RR;
void	push_a(t_list **stack_a, t_list **stack_b); //THIS IS PA
void	push_b(t_list **stack_a, t_list **stack_b); //THIS IS PB
//rrb reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
//reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.





//pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
//pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.





void	argument_handling(char **argv);
void	error_handling(void); //error handler Already Sorted/Errong Handling / No Arguments

//void	pa(void);  //push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
//void	pb(void);  //push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.