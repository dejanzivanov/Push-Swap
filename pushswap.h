#include <stdio.h> //for printf
#include <stdlib.h> //for free
#include <unistd.h> // for write

typedef struct s_list
{
	int value;
	struct s_list	*next;
}			t_list;

// Functions for input handling
void	just_the_two_of_us(long int *input);
long int 	*take_arg(int len, char *argv[]);
void	argument_handling(char **argv);
long int		ft_atoi(const char *str);
void	check_if_sorted(long int *arr, int length);
void	check_non_num(char *argv[], int l);
long int		*copy(long int *arr, int len);
long int		*bbsort(long int *arr, int len);
void	check_duplicate(long int *arr);
long int 	*get_sorted_indexes(long int *before, long int *after, int len);
size_t	ft_strlen(const char *s);
void	check_range(long int *arr, int len);
void	panic(long int *arr);

// Functions for struct management
int		init_struct(long int *indexed, int len);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	printlst(t_list *lst);
void	sort_stack(t_list *major_a, t_list *major_b, int len);
void	sort_3(t_list *head);
// Allowed moves
void	sa(t_list *head);  //swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
void	sb(t_list *head);  //swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
void	ss(t_list *major_a, t_list *major_b);  //sa and sb at the same time.
void	pa(t_list *major_a, t_list *major_b);  //push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
t_list	*pb(t_list *major_a, t_list *major_b);  //push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
t_list	*ra(t_list *head);  //rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
t_list	*rb(t_list *head_b);  //rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
void	rr(t_list *major_a, t_list *major_b);  //ra and rb at the same time.
t_list	*rra(t_list *head);
t_list	*ft_lst_penultimate(t_list *head);
t_list	*ft_antepenultimate(t_list *head);
t_list	*rrb(t_list *head_b);  //reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
void	rrr(t_list *major_a, t_list *major_b); //rra and rrb at the same time.
// Functions for sorting 5
void	sort_5(t_list *major_a, t_list *major_b, int len);
t_list	*bring_min_up(t_list *min_s, t_list *head, int len);
t_list	*find_min(t_list *head);
t_list	*call_ra(t_list *head, int counter);
t_list	*call_rra(t_list *head, int counter);