#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_dlist
{
	int				value;
	int				index;
	int				flag;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}t_dlist;

typedef struct s_stack
{
	char	name;
	int		count;
	t_dlist	*head;
	t_dlist	*tail;
}t_stack;

typedef struct s_program
{
	t_stack	a;
	t_stack	b;
	int		*sorted;
	t_list	*hist;
	int		main_flag;
	int		next_ind;
}t_program;

void	check_args(char **argv, int argc);
void	check_dups(t_program *prog);

void	init_prog(t_program *prog, char **argv, int argc);
void	ft_quicksort(int *arr, int size);

t_dlist	*create_node(int val, t_program *prog);
void	add_back(t_dlist *node, t_dlist **head, t_dlist **tail);
void	add_front(t_dlist *node, t_dlist **head, t_dlist **tail);
void	del_back(t_dlist **head, t_dlist **tail);
void	del_front(t_dlist **head, t_dlist **tail);

void	swap(t_stack *st, t_list **his);
void	push(t_stack *from, t_stack *to, t_program *prog);
void	rotate(t_stack *rot, t_program *prog);
void	rev_rot(t_stack *rot, t_program *prog);

void	algorithm(t_program *prog);
int		check_sort(t_program *prog);
void	small_alg(t_program *prog);

void	free_lists(t_dlist **head, t_list **his);

#endif
