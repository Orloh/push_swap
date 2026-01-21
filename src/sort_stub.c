/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:27:19 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/19 18:46:02 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
	if (min_idx <= size/2)
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
	if (size == 5)
		ft_push_min(stacks);
	if (size >= 4)
		ft_push_min(stacks);
	ft_tiny_sort(stacks);
	while (stacks->b)
		pa (stacks);
}

void	ft_big_sort(t_stacks *stacks)
{
	(void)stacks;
	return ;

}


