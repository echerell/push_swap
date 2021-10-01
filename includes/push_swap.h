#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_dlist
{
	int				value;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}t_dlist;

typedef struct s_stack
{
	char	name;
	int		count;
	int		is_sorted;
	t_dlist	*head;
	t_dlist	*tail;
}t_stack;

void	check_args(char **argv);
void	check_dups(t_dlist **head);

void	init_stacks(t_stack *a, t_stack *b);
void	init_list(char **argv, t_stack *a, t_list **his);

t_dlist	*create_node(int val, t_stack *a, t_stack *b, t_list **his);
void	add_back(t_dlist *node, t_dlist **head, t_dlist **tail);
void	add_front(t_dlist *node, t_dlist **head, t_dlist **tail);
void	del_back(t_dlist **head, t_dlist **tail);
void	del_front(t_dlist **head, t_dlist **tail);

void	swap(t_stack *st, t_list **his);
void	push(t_stack *from, t_stack *to, t_list **his);
void	rotate(t_stack *rot, t_stack *tmp, t_list **his);
void	rev_rot(t_stack *rot, t_stack *tmp, t_list **his);

void	free_all(t_dlist **head, t_list **his);

#endif
