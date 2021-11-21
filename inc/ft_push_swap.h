#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/incl/libft.h"
# include <limits.h>

typedef struct s_vars
{
	unsigned int	index;
	int				value;
	unsigned int	sorted_index;
	//char			*bin_num; //memory leeks consider on exxit
}			t_vars;

void	ft_del(void *content);
void	ft_binary_assignment(int i, t_list **stack_a, int *values);
void	ft_close_program(t_list *stack_a);
void	ft_sorting_helper(t_list **s_a, t_list **s_b, int i);
void	ft_reverse(char *x, int begin, int end);
//int		ft_check_base(char *base, int base_len, int i, int index);
//int		ft_print_base(int nbr, char *base, int base_len);
//void	ft_print_base2(int nbr, char *base, char *str, int i);
//char	*ft_put_nbrbase(int nbr, char *base);
int		ft_is_sorted(t_list **stack_a);
void	ft_reverse_rotate_helper(t_list **stack_a, t_list **stack_b);
int		ft_print_base(int nbr, char *base, int base_len); //delete this
int		ft_check_base(char *base, int base_len, int i, int index);
void	ft_handle_two(t_list **stack_a);
void	ft_handle_three(t_list **stack_a);
void	ft_handle_four(t_list **stack_a, t_list **stack_b);
void	ft_handle_five(t_list **stack_a, t_list **stack_b);
void	ft_handle_hundred(t_list **stack_a, t_list **stack_b);
void	ft_handle_five_hundred(t_list **stack_a, t_list **stack_b);
void	ft_argument_check(char **argv, t_list **stack_a, t_list **stack_b);
void	ft_free_list(t_list *head);
t_list	*ft_sorted_handler(char **argv, t_list *list);
void	ft_error_printer(t_list *list);
t_list	*ft_error_handler(char **argv, t_list *list);
void	ft_int_range_handler(char **argv, t_list *list);
void	ft_duplicate_handler(char **argv, t_list *list);

/*
**	Function bellow is RRA/RRB
**	rra : reverse rotate a - shift down all elements of stack a by 1.
**	The last element becomes the first one.
**
**	rrb : reverse rotate b - shift down all elements of stack b by 1.
**	The last element becomes the first one.
*/

void	reverse_rotate_stack(t_list **stack, char *operation);
void	rrr_helper(t_list **stack);

/*
**	Function bellow is RRR
**	rrr : rra and rrb at the same time.
*/

void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

/*
**	Function bellow is SA/SB
**	sa : swap a - swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements).
**
**	sb : swap b - swap the first 2 elements at the top of stack b.
**	Do nothing if there is only one or no elements).
*/

void	swap(t_list **stack, char *operation);

/*
**	Function bellow is SS
**	ss : sa and sb at the same time.
*/

void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	swap_helper(t_list **stack);

/*
**	Function bellow is RA/RB
*/

void	rotate_stack(t_list **stack, char *operation);
void	rr_helper(t_list **stack);

/*
**	Function bellow is RR
**	rr : ra and rb at the same time.
*/

void	rotate_a_b(t_list **stack_a, t_list **stack_b);

/*
**	Function bellow is PA
**	pa : push a - take the first element at the top of b and put it at the
**	top of a. Do nothing if b is empty.
*/

void	push_a(t_list **stack_a, t_list **stack_b);

/*
**	Function bellow is PB
**	pb : push b - take the first element at the top of a and put it at the
**	top of b. Do nothing if a is empty.
*/

void	push_b(t_list **stack_a, t_list **stack_b);
int		ft_min_finder(t_list **stack_a);
void	ft_index_update(t_list **stack);
void	argument_handling(char **argv);

/*
**
**	sa : swap a - swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements).
**
**	sb : swap b - swap the first 2 elements at the top of stack b.
**	Do nothing if there is only one or no elements).
**
**	ss : sa and sb at the same time.
**
**	pa : push a - take the first element at the top of b and put it at the
**	top of a. Do nothing if b is empty.
**
**	pb : push b - take the first element at the top of a and put it at the
**	top of b. Do nothing if a is empty.
**
**	ra : rotate a - shift up all elements of stack a by 1.
**	The first element becomes the last one.
**
**	rb : rotate b - shift up all elements of stack b by 1.
**	The first element becomes the last one.
**
**	rr : ra and rb at the same time.
**
**	rra : reverse rotate a - shift down all elements of stack a by 1.
**	The last element becomes the first one.
**
**	rrb : reverse rotate b - shift down all elements of stack b by 1.
**	The last element becomes the first one.
**
**	rrr : rra and rrb at the same time.
**
*/

#endif