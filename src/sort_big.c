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

void	ft_push_zero_bit(t_stacks *s, int bit, int *early_exit)
{
	int	size;

	size = ft_lstsize(s->a);
	while (size--)
	{
		if (!((ft_get_rank_node(s->a) >> bit) & 1))
			pb(s);
		else
			ra(s);
		if (ft_is_consecutive(s->a) && ft_is_consecutive_rev(s->b))
		{
			*early_exit = 1;
			break ;
		}
	}
}

void	ft_push_one_next_bit(t_stacks *s, int bit, int early_exit)
{
	int	size;

	size = ft_lstsize(s->b);

	if (early_exit)
		return ;
	while (size--)
	{
		if ((ft_get_rank_node(s->b) >> (bit + 1)) & 1)
			pa(s);
		else
			rb(s);
	}
	
}

void	ft_radix_sort(t_stacks *stacks, int max_bits)
{
	int	bit;
	int	early_exit;


	early_exit = 0;
	bit = -1;
	while (++bit < max_bits && !early_exit) 
	{
		ft_push_zero_bit(stacks, bit, &early_exit);
		ft_push_one_next_bit(stacks, bit, early_exit);
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
