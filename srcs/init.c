/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:04:46 by echerell          #+#    #+#             */
/*   Updated: 2021/10/04 22:37:24 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->name = 'a';
	b->name = 'b';
	a->count = 0;
	b->count = 0;
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
}

static void	init_list(char **argv, int argc, t_program *prog)
{
	int	i;
	int	j;
	int	val;

	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		add_back(create_node(val, prog), &(prog->a.head), &(prog->a.tail));
		prog->a.count++;
		j = 0;
		while (j < (argc - 1) && !(prog->a.tail->index))
		{
			if (prog->sorted[j] == val)
				prog->a.tail->index = j + 1;
			j++;
		}
		i++;
	}
}

static void	init_array(char **argv, int argc, t_program *prog)
{
	int	i;

	prog->sorted = (int *)malloc(sizeof(int) * (argc - 1));
	if (!(prog->sorted))
	{
		free_lists(&(prog->a.head), NULL);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (argc - 1))
	{
		prog->sorted[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_quicksort(prog->sorted, argc - 1);
}

void	init_prog(t_program *prog, char **argv, int argc)
{
	check_args(argv, argc);
	prog->sorted = NULL;
	prog->hist = NULL;
	prog->main_flag = 0;
	prog->next_ind = 1;
	init_array(argv, argc, prog);
	init_stacks(&(prog->a), &(prog->b));
	init_list(argv, argc, prog);
	check_dups(prog);
}
