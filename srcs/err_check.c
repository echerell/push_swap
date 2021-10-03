/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:00:42 by echerell          #+#    #+#             */
/*   Updated: 2021/10/03 20:49:02 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	isint(char *str)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i++] - '0');
		if (n < 0)
			return (0);
	}
	return (1);
}

void	check_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!(isint(argv[i])))
		{
			ft_putstr_fd("Error\n", 1);
			exit(EXIT_SUCCESS);
		}
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !j)
				j++;
			if (!ft_isdigit(argv[i][j]) || !argv[i][j])
			{
				ft_putstr_fd("Error\n", 1);
				exit(EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
}

void	check_dups(t_program *prog)
{
	t_dlist	*copy_din;
	t_dlist	*copy_stat;

	copy_din = (prog->a.head)->next;
	copy_stat = prog->a.head;
	while (copy_din != copy_stat)
	{
		if (copy_stat->value == copy_din->value)
		{
			free_lists(&(prog->a.head), NULL);
			free(prog->sorted);
			ft_putstr_fd("Error\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (copy_din->next == NULL)
		{
			copy_stat = copy_stat->next;
			if (copy_stat->next)
				copy_din = copy_stat;
			else
				copy_din = copy_din->prev;
		}
		copy_din = copy_din->next;
	}
}
