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
