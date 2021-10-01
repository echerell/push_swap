/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:07:57 by echerell          #+#    #+#             */
/*   Updated: 2021/10/01 22:40:39 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	lst_free(t_list **lst)
{
	t_list	*begin;
	t_list	*current;

	if (lst && *lst)
	{
		begin = *lst;
		current = NULL;
		while (begin->next)
		{
			current = begin;
			begin = begin->next;
			free(current);
		}
		free(begin);
		*lst = NULL;
	}
}

void	free_all(t_dlist **head, t_list **his)
{
	t_dlist	*copy;

	copy = *head;
	while (copy)
	{
		if (copy->next == NULL)
		{
			free(copy);
			copy = NULL;
		}
		else
		{
			copy = copy->next;
			free(copy->prev);
		}
	}
	if (his)
		lst_free(his);
}
