/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:04:46 by echerell          #+#    #+#             */
/*   Updated: 2021/10/10 18:08:13 by echerell         ###   ########.fr       */
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

static void	init_list(char **argv, int argc, t_program *prog, int i)
{
	int	val;
	int	j;
	int	shift;

	shift = i;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		add_back(create_node(val, prog), &(prog->a.head), &(prog->a.tail));
		prog->a.count++;
		j = 0;
		while (j < (argc - shift) && !(prog->a.tail->index))
		{
			if (prog->sorted[j] == val)
				prog->a.tail->index = j + 1;
			j++;
		}
		i++;
	}
}

static void	init_array(char **argv, int argc, t_program *prog, int i)
{
	int	j;
	int	shift;

	j = 0;
	shift = i;
	prog->sorted = (int *)malloc(sizeof(int) * (argc - i));
	if (!(prog->sorted))
	{
		free_lists(&(prog->a.head), NULL);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		prog->sorted[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	ft_quicksort(prog->sorted, argc - shift);
}

static char	**convert_args(int *alloc, int *shift, int *argc, char **argv)
{
	int		new_argc;

	new_argc = 0;
	argv = ft_split(argv[1], ' ');
	*alloc = 1;
	while (argv[new_argc])
		new_argc++;
	*shift = 0;
	*argc = new_argc;
	return (argv);
}

void	init_prog(t_program *prog, char **argv, int argc)
{
	char	**new_argv;
	int		new_argc;
	int		alloc;
	int		shift;

	alloc = 0;
	shift = 1;
	if (argc == 2)
		new_argv = convert_args(&alloc, &shift, &argc, argv);
	else
		new_argv = argv;
	new_argc = argc;
	check_args(new_argv, new_argc, shift);
	prog->sorted = NULL;
	prog->hist = NULL;
	prog->main_flag = 0;
	prog->next_ind = 1;
	init_array(new_argv, new_argc, prog, shift);
	init_stacks(&(prog->a), &(prog->b));
	init_list(new_argv, new_argc, prog, shift);
	check_dups(prog);
	if (alloc)
		free_argv(new_argv);
}
