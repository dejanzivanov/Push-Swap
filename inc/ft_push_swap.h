#include "../libft/incl/libft.h"
#include <limits.h>
#include <stdio.h> //REMOVE THIS

typedef struct s_vars
{
	int value;
	//void *next;
	void			*content;
	struct s_vars *next;

}			t_vars;

void	ft_sorted_handler(char **argv);
void	ft_error_printer();
void	ft_error_handler(char **argv);
void	ft_int_range_handler(char **argv);
void	ft_duplicate_handler(char **argv);
void	ft_sorted_handler(char **argv);

void	argument_handling(char **argv);
void	error_handling(void); //error handler Already Sorted/Errong Handling / No Arguments
void	sa(void);  //swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
void	sb(void);  //swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
void	ss(void);  //sa and sb at the same time.
void	pa(void);  //push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	pb(void);  //push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	ra(void);  //rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
void	rb(void);  //rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
void	rr(void);  //ra and rb at the same time.
void	rra(void);   //reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
void	rrb(void);  //reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
void	rrr(void); //rra and rrb at the same time.