/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:14:48 by echerell          #+#    #+#             */
/*   Updated: 2021/09/30 00:08:43 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

static void	print_list(t_dlist **ptr, int back)
{
	t_dlist *copy;

	copy = *ptr;
	while (copy)
	{
		printf("%i\n", copy->value);
		if (back)
			copy = copy->prev;
		else
			copy = copy->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	check_args(argv);
	init_stacks(&a, &b);
	init_list(argv, &(a.head), &(a.tail));
	check_dups(&(a.head));
	print_list(&(a.head), 0);
	//print_list(&tail, 1);
	free_all(&(a.head));

	return (0);
}
