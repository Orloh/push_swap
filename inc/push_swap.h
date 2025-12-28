/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:46:34 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/28 22:44:10 by orhernan         ###   ########.fr       */
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
}	t_stack_node;

int	*ft_sort_array(int *arr, int size);
int	*ft_parse_args(int argc, char **argv, int *size);

#endif
