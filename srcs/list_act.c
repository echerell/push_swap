/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:06:46 by echerell          #+#    #+#             */
/*   Updated: 2021/10/01 22:27:29 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*create_node(char *str, t_dlist **head, t_list **his)
{
	t_dlist	*node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!node)
	{
		free_all(head, his);
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->value = ft_atoi(str);
	return (node);
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

void	add_front(t_dlist *node, t_dlist **head, t_dlist **tail)
{
	if (!(*tail))
	{
		node->next = NULL;
		*tail = node;
	}
	else
	{
		node->next = *head;
		node->next->prev = node;
	}
	node->prev = NULL;
	*head = node;
}

void	del_back(t_dlist **head, t_dlist **tail)
{
	if (*tail)
	{
		if ((*tail)->prev == NULL)
		{
			free(*tail);
			*tail = NULL;
			*head = NULL;
		}
		else
		{
			*tail = (*tail)->prev;
			free((*tail)->next);
			(*tail)->next = NULL;
		}
	}
}

void	del_front(t_dlist **head, t_dlist **tail)
{
	if (*head)
	{
		if ((*head)->next == NULL)
		{
			free(*head);
			*head = NULL;
			*tail = NULL;
		}
		else
		{
			*head = (*head)->next;
			free((*head)->prev);
			(*head)->prev = NULL;
		}
	}
}
