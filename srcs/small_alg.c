/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:30:35 by echerell          #+#    #+#             */
/*   Updated: 2021/10/03 22:43:16 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	alg_3elem(t_program *prog, int sub)
{
	if (prog->a.head->index - sub == 1)
	{
		swap(&(prog->a), &(prog->hist));
		rotate(&(prog->a), prog);
	}
	else if (prog->a.head->index - sub == 2)
	{
		if (prog->a.head->next->index - sub == 1)
			swap(&(prog->a), &(prog->hist));
		else
			rev_rot(&(prog->a), prog);
	}
	else
	{
		if (prog->a.head->next->index - sub == 1)
			rotate(&(prog->a), prog);
		else
		{
			swap(&(prog->a), &(prog->hist));
			rev_rot(&(prog->a), prog);
		}
	}
}

static void	alg_4elem(t_program *prog, int sub)
{
	if (prog->a.head->next->index - sub + 1 == 1)
		rotate(&(prog->a), prog);
	else if (prog->a.tail->index - sub + 1 == 1)
		rev_rot(&(prog->a), prog);
	else if (prog->a.tail->prev->index - sub + 1 == 1)
	{
		rotate(&(prog->a), prog);
		rotate(&(prog->a), prog);
	}
	if (check_sort(prog))
	{
		push(&(prog->a), &(prog->b), prog);
		alg_3elem(prog, sub);
		push(&(prog->b), &(prog->a), prog);
	}
}

static void	alg_5elem(t_program *prog, int sub)
{
	if (prog->a.head->next->index == 1)
		rotate(&(prog->a), prog);
	else if (prog->a.head->next->next->index == 1)
	{
		rotate(&(prog->a), prog);
		rotate(&(prog->a), prog);
	}
	else if (prog->a.tail->index == 1)
		rev_rot(&(prog->a), prog);
	else if (prog->a.tail->prev->index == 1)
	{
		rev_rot(&(prog->a), prog);
		rev_rot(&(prog->a), prog);
	}
	if (check_sort(prog))
	{
		push(&(prog->a), &(prog->b), prog);
		alg_4elem(prog, sub);
		push(&(prog->b), &(prog->a), prog);
	}
}

void	small_alg(t_program *prog)
{
	if (prog->a.count == 2)
		swap(&(prog->a), &(prog->hist));
	else if (prog->a.count == 3)
		alg_3elem(prog, 0);
	else if (prog->a.count == 4)
		alg_4elem(prog, 1);
	else
		alg_5elem(prog, 2);
}
