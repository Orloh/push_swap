/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:46:34 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/19 18:46:04 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "ft_printf.h"
# include "libft.h"

typedef struct s_node_content
{
	int	value;
	int	rank;
}	t_node_content;

typedef struct s_int_arr
{
	int	*data;
	int	size;
}	t_int_arr;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

t_int_arr	ft_parse_args(int argc, char **argv);
t_list		*ft_init_stack(t_int_arr *arr);
void		ft_sort_array(t_int_arr *arr);
void		ft_free_int_arr(t_int_arr *arr);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		ft_tiny_sort(t_stacks *stacks);
void		ft_small_sort(t_stacks *stacks);
int			ft_is_sorted_stack(t_list *stack);
int			ft_is_sorted(t_int_arr *arr);

#endif
