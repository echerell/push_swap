/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:14:50 by echerell          #+#    #+#             */
/*   Updated: 2021/10/02 01:43:57 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *st, t_list **his)
{
	t_dlist	*copy;
	int		tmp;

	if (st->count > 1)
	{
		copy = st->head;
		copy = copy->next;
		tmp = (st->head)->value;
		(st->head)->value = copy->value;
		copy->value = tmp;
		if (st->name == 'a')
			ft_lstadd_back(his, ft_lstnew("sa"));
		else
			ft_lstadd_back(his, ft_lstnew("sb"));
	}
}

void	push(t_stack *from, t_stack *to, t_list **his)
{
	int	val;

	if (from->count != 0)
	{
		val = from->head->value;
		add_front(create_node(val, from, to, his), &(to->head), &(to->tail));
		del_front(&(from->head), &(from->tail));
		from->count--;
		to->count++;
		if (to->name == 'a')
			ft_lstadd_back(his, ft_lstnew("pa"));
		else
			ft_lstadd_back(his, ft_lstnew("pb"));
	}
}

void	rotate(t_stack *rot, t_stack *tmp, t_list **his)
{
	int	val;

	if (rot->count > 1)
	{
		val = rot->head->value;
		add_back(create_node(val, rot, tmp, his), &(rot->head), &(rot->tail));
		del_front(&(rot->head), &(rot->tail));
		if (rot->name == 'a')
			ft_lstadd_back(his, ft_lstnew("ra"));
		else
			ft_lstadd_back(his, ft_lstnew("rb"));
	}
}

void	rev_rot(t_stack *rot, t_stack *tmp, t_list **his)
{
	int	val;

	if (rot->count > 1)
	{
		val = rot->tail->value;
		add_front(create_node(val, rot, tmp, his), &(rot->head), &(rot->tail));
		del_back(&(rot->head), &(rot->tail));
		if (rot->name == 'a')
			ft_lstadd_back(his, ft_lstnew("rra"));
		else
			ft_lstadd_back(his, ft_lstnew("rrb"));
	}
}
