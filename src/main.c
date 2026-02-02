/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <orhernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:56:36 by orhernan          #+#    #+#             */
/*   Updated: 2026/02/02 18:37:25 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

static void	ft_sort_dispatcher(t_stacks *stacks, int size)
{
	if (size <= 5)
		ft_small_sort(stacks);
	else
		ft_big_sort(stacks);
}

void	ft_free_all(t_stacks *stacks, t_int_arr *arr)
{
	if (stacks)
	{
		ft_clear_stacks(stacks);
		free(stacks);
	}
	if (arr)
		ft_free_int_arr(arr);
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
		ft_free_all(stacks, &num_arr);
		ft_error();
	}
	stacks->b = NULL;
	ft_sort_dispatcher(stacks, num_arr.size);
	ft_free_all(stacks, &num_arr);
	return (0);
}
