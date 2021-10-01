/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:14:50 by echerell          #+#    #+#             */
/*   Updated: 2021/10/01 16:17:12 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *st, t_list **his)
{
	t_dlist	*copy;
	int		tmp;

	if (st->count != 1)
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
