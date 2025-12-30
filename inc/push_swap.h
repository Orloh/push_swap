/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:46:34 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/29 17:21:19 by orhernan         ###   ########.fr       */
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

void	ft_sort_array(t_int_arr arr);
t_int_arr	ft_parse_args(int argc, char **argv);
void	ft_free_int_arr(t_int_arr arr);

#endif
