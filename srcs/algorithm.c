/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:34:24 by echerell          #+#    #+#             */
/*   Updated: 2021/10/03 22:33:04 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_program *prog)
{
	t_dlist *copy;

	copy = prog->a.head;
	while (copy && copy->next)
	{
		if (copy->index > copy->next->index)
			return (1);
		copy = copy->next;
	}
	return (0);
}

void	algorithm(t_program *prog)
{
	if (check_sort(prog))
	{
		if (prog->a.count < 6)
			small_alg(prog);
	}
}
