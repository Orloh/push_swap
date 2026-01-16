/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:32:05 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/11 21:13:26 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
	return (1);
}

void	ra(t_stacks *stacks)
{
	if (ft_rotate(&(stacks->a)))
		ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	if (ft_rotate(&(stacks->b)))
		ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	if (!stacks->a || !stacks->b || !stacks->a->next || !stacks->b->next)
		return ;
	ft_rotate(&(stacks->a));
	ft_rotate(&(stacks->b));
	ft_printf("rr\n");
}
