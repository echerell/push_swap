/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:04:46 by echerell          #+#    #+#             */
/*   Updated: 2021/09/30 00:05:53 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->is_sorted = 0;
	b->is_sorted = 0;
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
}

void	init_list(char **argv, t_dlist **head, t_dlist **tail)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		add_back(create_node(argv[i], head), head, tail);
	i++;
	}
}
