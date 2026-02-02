/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <orhernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:27:19 by orhernan          #+#    #+#             */
/*   Updated: 2026/02/02 18:53:02 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

static int	ft_get_max_bits(t_list *stack)
{
	int	max_rank;
	int	max_bits;

	max_rank = 0;
	while (stack)
	{
		if (((t_node_content *)stack->content)->rank > max_rank)
			max_rank = ((t_node_content *)stack->content)->rank;
		stack = stack->next;
	}
	max_bits = 0;
	while ((max_rank >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	ft_get_rank_node(t_list *stack_head)
{
	return (((t_node_content *)stack_head->content)->rank);
}

int	ft_is_consecutive(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (ft_get_rank_node(stack) + 1 != ft_get_rank_node(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_consecutive_rev(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (ft_get_rank_node(stack) != ft_get_rank_node(stack->next) + 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_radix_sort(t_stacks *stacks, int max_bits)
{
	int	i;
	int	size;

	i = -1;
	while (++i < max_bits)
	{
		size = ft_lstsize(stacks->a);
		while (size--)
		{
			if (!((ft_get_rank_node(stacks->a) >> i) & 1))
				pb(stacks);
			else
				ra(stacks);
			if (ft_is_consecutive(stacks->a) && \
				ft_is_consecutive_rev(stacks->b))
			{
				i = max_bits;
				break ;
			}
		}
		size = ft_lstsize(stacks->b);
		while (size-- && (i != max_bits))
		{
			if ((ft_get_rank_node(stacks->b) >> (i + 1)) & 1)
				pa(stacks);
			else
				rb(stacks);
		}
	}
	while (stacks->b)
		pa(stacks);
}

void	ft_big_sort(t_stacks *stacks)
{
	if (ft_is_consecutive(stacks->a))
		return ;
	if (ft_is_consecutive_rev(stacks->a))
	{
		while (ft_lstsize(stacks->a) > 0)
			pb(stacks);
		while (ft_lstsize(stacks->b) > 0)
			pa(stacks);
		return ;
	}
	ft_radix_sort(stacks, ft_get_max_bits(stacks->a));
}
