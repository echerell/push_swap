/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:49:30 by echerell          #+#    #+#             */
/*   Updated: 2021/10/06 14:51:23 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_hist(void *act)
{
	ft_putstr_fd(act, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static int	rule_cond2(t_list *copy)
{
	return ((!ft_strncmp(copy->content, "pa", 2)
			&& !ft_strncmp(copy->next->content, "pb", 2))
		|| (!ft_strncmp(copy->content, "pb", 2)
			&& !ft_strncmp(copy->next->content, "pa", 2))
		|| (!ft_strncmp(copy->content, "rr", 3)
			&& !ft_strncmp(copy->next->content, "rrr", 3))
		|| (!ft_strncmp(copy->content, "rrr", 3)
			&& !ft_strncmp(copy->next->content, "rr", 3)));
}

static int	rule_cond(char *rule, t_list *copy)
{
	if (!ft_strncmp("rrr", rule, 3))
	{
		if ((!ft_strncmp(copy->content, "rra", 3)
				&& !ft_strncmp(copy->next->content, "rrb", 3))
			|| (!ft_strncmp(copy->content, "rrb", 3)
				&& !ft_strncmp(copy->next->content, "rra", 3)))
			return (1);
	}
	else if (!ft_strncmp("rr", rule, 2))
	{
		if ((!ft_strncmp(copy->content, "ra", 2)
				&& !ft_strncmp(copy->next->content, "rb", 2))
			|| (!ft_strncmp(copy->content, "rb", 2)
				&& !ft_strncmp(copy->next->content, "ra", 2)))
			return (1);
	}
	else if (!ft_strncmp("empty", rule, 5))
	{
		if (rule_cond2(copy))
			return (1);
	}
	return (0);
}

static void	change_rule(char *rule, t_list *copy, t_list *prev)
{
	t_list	*del1;
	t_list	*del2;

	if (!ft_strncmp("empty", rule, 5))
	{
		del1 = copy;
		del2 = copy->next;
		prev->next = copy->next->next;
		free(del1);
		free(del2);
	}
	else
	{
		copy->content = rule;
		del1 = copy->next;
		copy->next = copy->next->next;
		free(del1);
	}
}

void	check_hist(t_list **hist)
{
	t_list	*copy;
	t_list	*prev;

	copy = *hist;
	prev = *hist;
	while (copy && copy->next)
	{
		if (rule_cond("rr", copy))
			change_rule("rr", copy, prev);
		else if (rule_cond("rrr", copy))
			change_rule("rrr", copy, prev);
		else if (rule_cond("empty", copy))
		{
			change_rule("empty", copy, prev);
			copy = *hist;
		}
		prev = copy;
		copy = copy->next;
	}
}
