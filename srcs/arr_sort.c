/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:54:04 by echerell          #+#    #+#             */
/*   Updated: 2021/10/03 14:57:22 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	recurse(int *arr, int i, int j, int size)
{
	if (j > 0)
		ft_quicksort(arr, j + 1);
	if (i < size)
		ft_quicksort(&arr[i], size - i);
}

void	ft_quicksort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	mid;

	i = 0;
	j = size - 1;
	mid = arr[size / 2];
	while (i <= j)
	{
		while (arr[i] < mid)
			i++;
		while (arr[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	recurse(arr, i, j, size);
}
