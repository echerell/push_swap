/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:14:48 by echerell          #+#    #+#             */
/*   Updated: 2021/10/01 22:42:26 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

static void	print_hist(void* act)
{
	ft_putstr_fd(act, 1);
	ft_putchar_fd('\n', 1);
}

static void	print_list(t_dlist **ptr, int back)
{
	t_dlist	*copy;

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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_list	*history;

	history = NULL;
	if (argc <= 2)
		exit(EXIT_SUCCESS);
	check_args(argv);
	init_stacks(&a, &b);
	init_list(argv, &a, &history);
	check_dups(&(a.head));
	swap(&a, &history);
	print_list(&(a.head), 0);
	printf("count = %i\n", a.count);
	printf("\nhistory:\n");
	ft_lstiter(history, print_hist);
	free_all(&(a.head), &history);
	return (0);
}
