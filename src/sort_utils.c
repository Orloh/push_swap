/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:22:39 by orhernan          #+#    #+#             */
/*   Updated: 2026/02/04 21:33:55 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(t_list *stack)
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

int	ft_get_rank_node(t_list *stack_head)
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
