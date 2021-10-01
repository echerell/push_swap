/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:04:46 by echerell          #+#    #+#             */
/*   Updated: 2021/10/01 22:31:54 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->name = 'a';
	b->name = 'a';
	a->count = 0;
	b->count = 0;
	a->is_sorted = 0;
	b->is_sorted = 0;
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
}

//change head and tail to history
void	init_list(char **argv, t_stack *a, t_list **his)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		add_back(create_node(argv[i], &(a->head), his), &(a->head), &(a->tail));
		i++;
		a->count++;
	}
}
