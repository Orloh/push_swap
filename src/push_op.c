/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:28:33 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/11 18:02:13 by orhernan         ###   ########.fr       */
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
	ft_lstadd_front(dst, tmp);
	return (1);
}

void	pa(t_stacks *stacks)
{
	if (ft_push(&(stacks->b), &(stacks->a)))
		ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	if (ft_push(&(stacks->a), &(stacks->b)))
		ft_printf("pb\n");
}
