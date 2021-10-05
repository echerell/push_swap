/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:34:24 by echerell          #+#    #+#             */
/*   Updated: 2021/10/05 03:36:24 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

int	check_sort(t_program *prog)
{
	t_dlist	*copy;

	copy = prog->a.head;
	while (copy->next)
	{
		if (copy->index > copy->next->index)
			return (1);
		copy = copy->next;
	}
	return (0);
}

static int	isless_mid(t_dlist **head, int mid)
{
	t_dlist	*copy;

	copy = *head;
	while (copy)
	{
		if (copy->index >= mid)
			return (1);
		copy = copy->next;
	}
	return (0);
}

static int	max_ind(t_dlist **head)
{
	t_dlist *copy;
	int		max;

	copy = *head;
	max = 1;
	while (copy)
	{
		if (copy->index > max)
			max = copy->index;
		copy = copy->next;
	}
	return (max);
}

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
			if (prog->b.head->index >= mid || prog->b.head->index == prog->next_ind)
			{
				push(&(prog->b), &(prog->a), prog);
				prog->a.head->flag = prog->main_flag;
			}
			else
				rotate(&(prog->b), prog);
			if (prog->a.head->index == prog->next_ind)
			{
				rotate(&(prog->a), prog);
				prog->next_ind++;
			}
		}
	}
}

static void	big_alg(t_program *prog)
{
	int	mid;
	int	cur_flag;

	mid = prog->a.count / 2 + prog->next_ind;
	while (prog->b.count != mid)
	{
		if (prog->a.head->index <= mid)
			push(&(prog->a), &(prog->b), prog);
		else
			rotate(&(prog->a), prog);
	}
	while (check_sort(prog))
	{
		b_manage(prog, mid);
		while (prog->a.head->flag)
		{
			cur_flag = prog->a.head->flag;
			while (prog->a.head->flag == cur_flag || prog->a.head->index == prog->next_ind)
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
				mid = max_ind(&(prog->b.head));
			b_manage(prog, mid);
		}
		while (prog->a.head->index == prog->next_ind)
		{
			rotate(&(prog->a), prog);
			prog->next_ind++;
		}
		mid = (prog->a.count - prog->next_ind) / 2 + prog->next_ind;
		while (prog->a.head->index >= prog->next_ind)
		{
			if (prog->a.head->index <= mid)
				push(&(prog->a), &(prog->b), prog);
			else
				rotate(&(prog->a), prog);
		}
		while (prog->a.tail->index != prog->next_ind - 1)
			rev_rot(&(prog->a), prog);
	}
	/*b_manage(prog, mid);
	while (prog->a.head->flag)
	{
		cur_flag = prog->a.head->flag;
		while (prog->a.head->flag == cur_flag || prog->a.head->index == prog->next_ind)
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
			mid = max_ind(&(prog->b.head));
		b_manage(prog, mid);
	}*/
}

void	algorithm(t_program *prog)
{
	if (check_sort(prog))
	{
		if (prog->a.count < 6)
			small_alg(prog);
		else
			big_alg(prog);
	}
}
