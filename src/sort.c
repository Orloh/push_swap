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
	while (++i < arr->size - 1)
	{
		if (!(arr->data[i] < arr->data[i + 1]))
			return (0);
	}
	return (1);
}

/*
 * Checks if the stack is sorted in strictly ascending order by comparing
 * node ranks.
 */
int	ft_is_sorted_stack(t_list *stack)
{
	t_node_content	*current;
	t_node_content	*next;

	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		current = (t_node_content *)stack->content;
		next = (t_node_content *)stack->next->content;
		if (current->rank >= next->rank)
			return (0);
		stack = stack->next;
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

/*
 * Sorts a stack of exactly three elements using a maximum of two moves.
 * It compares the ranks of the three nodes to identify one of the five
 * possible unsorted permutations and applies the optimal sequence of sa,
 * ra, or rra to achive ascending order.
*/
void	ft_tiny_sort(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	if (ft_is_sorted_stack(stacks->a))
		return ;
	a = ((t_node_content *)stacks->a->content)->rank;
	b = ((t_node_content *)stacks->a->next->content)->rank;
	c = ((t_node_content *)stacks->a->next->next->content)->rank;
	if (a < b && b > c && a < c)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (a > b && b < c && a < c)
		sa(stacks);
	else if (a < b && b > c && a > c)
		rra(stacks);
	else if (a > b && b < c && a > c)
		ra(stacks);
	else if (a > b && b > c)
	{
		sa(stacks);
		rra(stacks);
	}
}
