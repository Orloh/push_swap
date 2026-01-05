/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:28:33 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/05 19:02:33 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if(ft_push(stack_b, stack_a))
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if(ft_push(stack_a, stack_b))
		ft_printf("pb\n");
}
