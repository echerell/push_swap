/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:22:22 by echerell          #+#    #+#             */
/*   Updated: 2021/10/06 14:23:07 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	isless_mid(t_dlist **head, int mid)
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

int	max_ind(t_dlist **head)
{
	t_dlist	*copy;
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

void	move_bot(t_program *prog)
{
	while (prog->a.head->index == prog->next_ind)
	{
		rotate(&(prog->a), prog);
		prog->next_ind++;
	}
}

int	init_lmr(int first, int *mid, int *right, t_program *prog)
{
	if (first)
	{
		*mid = prog->a.count / 2 + prog->next_ind;
		*right = *mid;
		return (prog->b.count);
	}
	else
	{
		*mid = (prog->a.count - prog->next_ind) / 2 + prog->next_ind;
		*right = 1;
		return (prog->a.head->index);
	}
}
