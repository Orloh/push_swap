/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <orhernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:13:21 by orhernan          #+#    #+#             */
/*   Updated: 2026/02/02 18:20:31 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_get_min_idx(t_list *stack)
{
	int	min_rank;
	int	min_idx;
	int	curr_idx;

	min_rank = INT_MAX;
	min_idx = 0;
	curr_idx = 0;
	while (stack)
	{
		if (((t_node_content *)stack->content)->rank < min_rank)
		{
			min_rank = ((t_node_content *)stack->content)->rank;
			min_idx = curr_idx;
		}
		stack = stack->next;
		curr_idx++;
	}
	return (min_idx);
}

static void	ft_push_min(t_stacks *stacks)
{
	int	min_idx;
	int	size;

	size = ft_lstsize(stacks->a);
	min_idx = ft_get_min_idx(stacks->a);
	if (min_idx <= size / 2)
	{
		while (min_idx-- > 0)
			ra(stacks);
	}
	else
	{
		while (min_idx++ < size)
			rra(stacks);
	}
	pb(stacks);
}

void	ft_small_sort(t_stacks *stacks)
{
	int	size;

	if (ft_is_sorted_stack(stacks->a))
		return ;
	size = ft_lstsize(stacks->a);
	if (size == 2)
	{
		sa(stacks);
		return ;
	}
	if (size == 5)
		ft_push_min(stacks);
	if (size >= 4)
		ft_push_min(stacks);
	ft_tiny_sort(stacks);
	while (stacks->b)
		pa (stacks);
}
