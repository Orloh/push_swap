/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:13:21 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/28 22:43:56 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Checks if the integer array is sorted in strictly ascending order.
 */
int	ft_is_sorted(t_int_arr *arr)
{
	int	i;

	i = -1;
	if (!arr || !arr->data)
		return (0);
	while(++i < arr->size - 1)
	{
		if (!(arr->data[i] < arr->data[i + 1]))
			return (0);
	}
	return (1);
}

/*
 * Sorts an array of integers in place and returns a pointer
 */
void	ft_sort_array(t_int_arr *arr)
{
	int	i;
	int	j;
	int	tmp;

	if (!arr->data || arr->size <= 1)
		return ;
	i = 1;
	while (i < arr->size)
	{
		tmp = arr->data[i];
		j = i - 1;
		while (j >= 0 && arr->data[j] > tmp)
		{
			arr->data[j + 1] = arr->data[j];
			j--;
		}
		arr->data[j + 1] = tmp;
		i++;
	}
	return ;
}
