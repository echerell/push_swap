/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:07:57 by echerell          #+#    #+#             */
/*   Updated: 2021/09/30 00:08:23 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_dlist **head)
{
	t_dlist *copy;

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
}
