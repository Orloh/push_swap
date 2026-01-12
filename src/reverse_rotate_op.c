/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:09:47 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/12 17:34:13 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stacks *stacks)
{
	if (ft_reverse_rotate(&(stacks->a)))
		ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	if (ft_reverse_rotate(&(stacks->b)))
		ft_printf("rrb\n ");
}
