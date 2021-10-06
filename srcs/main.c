/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:14:48 by echerell          #+#    #+#             */
/*   Updated: 2021/10/06 14:50:58 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	init_prog(&prog, argv, argc);
	algorithm(&prog);
	check_hist(&prog.hist);
	ft_lstiter(prog.hist, print_hist);
	free_lists(&(prog.a.head), &(prog.hist));
	free(prog.sorted);
	return (0);
}
