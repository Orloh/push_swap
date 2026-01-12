/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:22:09 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/12 17:56:57 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = (*stack);
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_stacks *stacks)
{
	if (ft_swap(&(stacks->a)))
		ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	if (ft_swap(&(stacks->b)))
		ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	if (!stacks->a || !stacks->b || !stacks->a->next || !stacks->b->next)
		return;
	ft_swap(&(stacks->a));
	ft_swap(&(stacks->b));
	ft_printf("ss\n");
}
