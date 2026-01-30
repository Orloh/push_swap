/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:27:19 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/19 18:46:02 by orhernan         ###   ########.fr       */
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

void	ft_big_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = ft_get_max_bits(stacks->a);
	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(stacks->a);
		j = 0;
		while (j++ < size)
		{
			if (!((((t_node_content *)stacks->a->content)->rank >> i) & 1))
				pb(stacks);
			else
				ra(stacks);
		}
		while (stacks->b)
			pa(stacks);
		i++;
	}
	return ;
}

static int	ft_get_rank_node(t_list *stack_head)
{
	return (((t_node_content *)stack_head->content)->rank);
}

void	ft_big_sort_base3(t_stacks *stacks)
{
	int	i;
	int	j;
	int	size;
	int	max_trits;
	int	pow_3;

	max_trits = 6;
	pow_3 = 1;
	for(i = 0; i < max_trits; i++)
	{
		size = ft_lstsize(stacks->a);
		for (j = 0; j < size; j++)
		{
			int digit = (ft_get_rank_node(stacks->a) / pow_3) % 3;
			if (digit == 0)
			{
				pb (stacks);
				rb (stacks);
			}
			else if (digit == 1)
				pb(stacks);
			else
				ra(stacks);
		}
		while (stacks->b)
		{
			if (ft_get_rank_node(stacks->b) / pow_3 % 3 == 1)
				pa(stacks);
   			else
			{
				rrb(stacks);
				pa(stacks);
			}
		}
		pow_3 *= 3;
	}
}
