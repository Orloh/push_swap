/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:56:36 by orhernan          #+#    #+#             */
/*   Updated: 2026/01/27 19:52:30 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_int_arr	num_arr;

	if (argc < 2)
		return (0);
	num_arr = ft_parse_args(argc, argv);
	if (!num_arr.data)
		ft_error();
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error();
	stacks->a = ft_init_stack(&num_arr);
	if (!stacks->a)
	{
		free(stacks);
		ft_free_int_arr(&num_arr);
		ft_error();
	}
	stacks->b = NULL;
	if (num_arr.size <= 5)
		ft_small_sort(stacks);
	else
		ft_big_sort(stacks);	
	clear_stacks(stacks);
	free(stacks);
	ft_free_int_arr(&num_arr);
	return (0);
}
