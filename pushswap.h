#include <stdio.h> //for printf
#include <stdlib.h> //for free
#include <unistd.h> // for write

typedef struct s_list
{
	int value;
	struct s_list	*next;
}			t_list;

// Functions for input handling
void		just_the_two_of_us(t_list **head);
long int 	*take_arg(int len, char *argv[]);
void		argument_handling(char **argv);
long int	ft_atoi(const char *str);
void		check_if_sorted(long int *arr, int length);
void		check_non_num(char *argv[], int l);
long int	*copy(long int *arr, int len);
long int	*bbsort(long int *arr, int len);
void		check_duplicate(long int *arr, int len);
long int 	*get_sorted_indexes(long int *before, long int *after, int len);
size_t		ft_strlen(const char *s);
void		check_range(long int *arr, int len);
void		panic(long int *arr);
// Functions for struct management
int		init_struct(long int *indexed, int len);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	printlst(t_list *lst);
void	sort_stack(t_list *major_a, t_list *major_b, int len);
void	sort_3(t_list **head);
// Allowed moves
void	sa(t_list **head);
void	sb(t_list *head);
void	ss(t_list *major_a, t_list *major_b);
void	pa(t_list **major_a, t_list **major_b);
void	pb(t_list **major_a, t_list **major_b);
void	ra(t_list **head);
void	rb(t_list **head_b); 
void	rr(t_list **major_a, t_list **major_b);
void	rra(t_list **head);
void	rrb(t_list **head_b);  
void	rrr(t_list **major_a, t_list **major_b); 
// Functions for sorting 5
t_list	*ft_lst_penultimate(t_list *head);
t_list	*ft_antepenultimate(t_list *head);
void	bring_min_up(int min_v, t_list **head, int len);
int		find_min(t_list **head);
void	call_ra(t_list **head, int counter);
void	call_rra(t_list **head, int counter);
void	sort_5(t_list *major_a, t_list *major_b, int len);