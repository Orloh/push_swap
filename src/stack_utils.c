/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <orhernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:21:05 by orhernan          #+#    #+#             */
/*   Updated: 2026/02/02 18:49:21 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_clear_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		ft_lstclear(&(stacks->a), free);
	if (stacks->b)
		ft_lstclear(&(stacks->b), free);
}

/*
 * Searches for a value in a sorted integer array and returns its index(rank).
 * Returns -1 if the value is not found.
 */
int	ft_get_rank(int val, t_int_arr *sorted_arr)
{
	int	low;
	int	mid;
	int	high;

	if (!sorted_arr || !sorted_arr->data)
		return (-1);
	low = 0;
	high = (sorted_arr->size) - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sorted_arr->data[mid] == val)
			return (mid);
		if (sorted_arr->data[mid] < val)
			low = mid + 1;
		else
			high = mid -1;
	}
	return (-1);
}

/*
 * Allocates and initializes a t_node_content struct
 */
t_node_content	*ft_create_content(int val, t_int_arr *sorted_arr)
{
	t_node_content	*c;

	c = malloc(sizeof(t_node_content));
	if (!c)
		return (NULL);
	c->value = val;
	c->rank = ft_get_rank(val, sorted_arr);
	return (c);
}

/*
 * Creates a sorted copy of thee input array to serve as a rank reference.
 * Uses ft_memcpy to duplicate data and ft_sort_array to sort it in place.
 */
t_int_arr	ft_get_sorted_arr(t_int_arr *arr)
{
	t_int_arr	sorted;

	sorted.size = arr->size;
	sorted.data = ft_calloc(arr->size, sizeof(int));
	if (!sorted.data)
		return (sorted);
	ft_memcpy(sorted.data, arr->data, arr->size * sizeof(int));
	ft_sort_array(&sorted);
	if (!ft_is_sorted(&sorted))
		ft_free_int_arr(&sorted);
	return (sorted);
}

/*
 * Initializes a stack from a parsed integer array.
 * If any allocation fails, it clears the list and returns NULL.
 */
t_list	*ft_init_stack(t_int_arr *arr)
{
	int			i;
	t_list		*new_stack;
	t_list		*new_node;
	t_int_arr	sorted;

	if (!arr || !arr->data)
		return (NULL);
	sorted = ft_get_sorted_arr(arr);
	if (!sorted.data)
		return (NULL);
	new_stack = NULL;
	i = -1;
	while (++i < arr->size)
	{
		new_node = ft_lstnew(ft_create_content(arr->data[i], &sorted));
		if (!new_node)
		{
			ft_lstclear(&new_stack, free);
			break ;
		}
		ft_lstadd_back(&new_stack, new_node);
	}
	return (ft_free_int_arr(&sorted), new_stack);
}
