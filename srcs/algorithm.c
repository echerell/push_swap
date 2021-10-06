/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:34:24 by echerell          #+#    #+#             */
/*   Updated: 2021/10/06 14:23:19 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_program *prog)
{
	if (check_sort(prog) && prog->a.count != 1)
	{
		if (prog->a.count < 6)
			small_alg(prog);
		else
			big_alg(prog);
	}
}
