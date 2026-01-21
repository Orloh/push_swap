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

static void	ft_push_min(t_stacks *stacks)
{
	(void) stacks;
	return ;
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


