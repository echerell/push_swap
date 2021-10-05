/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:14:48 by echerell          #+#    #+#             */
/*   Updated: 2021/10/05 03:32:33 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

static void	print_hist(void *act)
{
	ft_putstr_fd(act, 1);
	ft_putchar_fd('\n', 1);
}

/*static void	print_array(int *arr, int n)
{
	int	i;

	i = 0;
	printf("-----array-----\n");
	while (i < n)
	{
		printf("%i\n", arr[i]);
		i++;
	}
}

static void	print_list(t_dlist **ptr, int back)
{
	t_dlist	*copy;

	copy = *ptr;
	while (copy)
	{
		printf("%i\t\tindex:%i\n", copy->value, copy->index);
		if (back)
			copy = copy->prev;
		else
			copy = copy->next;
	}
}

static void	print_step(t_program *prog)
{
	printf("main_flag = %i\nnext_ind = %i\n", prog->main_flag, prog->next_ind);
	printf("-----A-----\n");
	print_list(&(prog->a.head), 0);
	printf("count = %i\n", prog->a.count);
	printf("-----B-----\n");
	print_list(&(prog->b.head), 0);
	printf("count = %i\n", prog->b.count);
}

static void	print_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr_fd(argv[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);

}
*/
int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	init_prog(&prog, argv, argc);
	//print_args(argv, argc);
	//print_array(prog.sorted, prog.a.count);
	algorithm(&prog);
	//print_step(&prog);
	//printf("\nhistory:\n");
	ft_lstiter(prog.hist, print_hist);
	free_lists(&(prog.a.head), &(prog.hist));
	free(prog.sorted);
	return (0);
}
