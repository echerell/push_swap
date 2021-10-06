/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:20:23 by echerell          #+#    #+#             */
/*   Updated: 2021/10/06 14:25:14 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	b_manage(t_program *prog, int max)
{
	int	mid;
	int	new_max;

	mid = max;
	while (prog->b.count)
	{
		new_max = mid;
		mid = (new_max - prog->next_ind) / 2 + prog->next_ind;
		prog->main_flag++;
		while (isless_mid(&(prog->b.head), mid))
		{
			if (prog->b.head->index >= mid
				|| prog->b.head->index == prog->next_ind)
			{
				push(&(prog->b), &(prog->a), prog);
				prog->a.head->flag = prog->main_flag;
			}
			else
				rotate(&(prog->b), prog);
			move_bot(prog);
		}
	}
}

static void	shift_sortpart(t_program *prog)
{
	while (prog->a.tail->index != prog->next_ind - 1)
	{
		if (prog->next_ind >= prog->a.count / 2)
		{
			rev_rot(&(prog->a), prog);
			if (prog->b.count && prog->b.head->index != prog->next_ind)
				rev_rot(&(prog->b), prog);
		}
		else
		{
			rotate(&(prog->a), prog);
			if (prog->b.count && prog->b.head->index != prog->next_ind)
				rotate(&(prog->b), prog);
		}
	}
}

static void	push_notsorted(t_program *prog, int *mid, int first)
{
	int	left;
	int	right;

	left = init_lmr(first, mid, &right, prog);
	while (left != right)
	{
		if (prog->a.head->index <= *mid)
			push(&(prog->a), &(prog->b), prog);
		else
		{
			rotate(&(prog->a), prog);
			if (prog->b.count && prog->b.head->index != prog->next_ind)
				rotate(&(prog->b), prog);
		}
		if (first)
			left = prog->b.count;
		else
			left = prog->a.head->index;
	}
}

static void	push_batch(t_program *prog, int *mid)
{
	int	cur_flag;

	cur_flag = prog->a.head->flag;
	while (prog->a.head->flag == cur_flag
		|| prog->a.head->index == prog->next_ind)
	{
		if (prog->a.head->index == prog->next_ind)
		{
			rotate(&(prog->a), prog);
			prog->next_ind++;
		}
		else
		{
			push(&(prog->a), &(prog->b), prog);
			prog->b.head->flag = cur_flag;
		}
	}
	if (prog->b.head)
		*mid = max_ind(&(prog->b.head));
}

void	big_alg(t_program *prog)
{
	int	mid;

	push_notsorted(prog, &mid, 1);
	while (check_sort(prog) || prog->b.count)
	{
		b_manage(prog, mid);
		while (prog->a.head->flag)
		{
			push_batch(prog, &mid);
			b_manage(prog, mid);
		}
		push_notsorted(prog, &mid, 0);
		shift_sortpart(prog);
	}
}
