/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:06:46 by echerell          #+#    #+#             */
/*   Updated: 2021/09/30 00:20:33 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*create_node(char *str, t_dlist **head)
{
	t_dlist *node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!node)
	{
		free_all(head);
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->value = ft_atoi(str);
	return node;
}

void	add_back(t_dlist *node, t_dlist **head, t_dlist **tail)
{
	if (!(*head))
	{
		node->prev = NULL;
		*head = node;
	}
	else
	{
		node->prev = *tail;
		node->prev->next = node;
	}
	node->next = NULL;
	*tail = node;

}
